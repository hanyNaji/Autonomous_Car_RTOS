/*
 * app.c
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */

/****** Includes *******/

/*** HAL ***/
/* UltraSonic */
/* Motors */
/* LCD */
/* LDRs */
/* On board Temperature Sensor */
#include "HAL/ultraSonic/ultraSonic.h"
#include "HAL/LCD_Driver/LCD_Driver.h"
#include "HAL/DC_motor/DC_motor.h"
#include "HAL/Sensors/Sensor.h"

#include "MCAL/Tiva_DIO/Tiva_DIO.h"
#include "utils/tm4c123gh6pm.h"
#include "app.h"




/************************************/

/******* #Defines - MACROs *******/

#define TASK_1_PERIOD   10U
#define TASK_2_PERIOD   5U
#define TASK_3_PERIOD   3U


#define SW1    PF4
#define SW2    PF0

#define QUEUE_LENGTH    2

/******* Global variables *******/
volatile uint8_t start_flag = 0;
const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

/* Define queue handles for ultrasonic and LDR data */
QueueHandle_t ultrasonic_Queue;
QueueHandle_t ldr_Diff_Queue;

Output_Value_Type toggle = LOW;

volatile uint8_t  elapsed_time_S ;        /* To calculate seconds of the stop watch */

GPTM_Struct GPTM_Timer0 = {
    TIMER0,           /* Timer type */
    0x00UL,             /* Pre-scale value */
    PERIODIC,            /* Timer mode */
    CONCAT,           /* Concatenation mode */
    EDGE_TIME,          /* Capture mode */
    CC_MODE,            /* Timer alternate mode */
    COUNT_DWON,           /* Timer count direction */
    NEGATIVE,               /* Event mode */
    ENABLE_INT,        /* Match interrupt type */
    WAIT_TAEN_BIT,      /* Start mode */
    DIS_SnapSh,         /* Snapshot mode */
    DIS_PWMInt,         /* PWM interrupt type */
    NEXT_CYCLE,         /* Match register update */
    CCP_LOW             /* PWM legacy operation */
};


/************ Interrupts ************/
void Int_Timer0_Handler(void)
{
    TIMER0_ICR_R |=(1U<<0);
    if(elapsed_time_S==59U){
        elapsed_time_S = 0U;
        start_flag = 0;
        car_Stop();
        GPTM_Disable(GPTM_Timer0.timer);
        DIO_WritePin(PF1, HIGH);
        DIO_WritePin(PF3, LOW);
    }
    else {
        elapsed_time_S++;
        toggle = !toggle;
        DIO_WritePin(PF3, toggle);

    }

}

/* GPIO PORTF Interrupt handler */
void GPIOFIntHandler(void)
{
    if (GPIO_PORTF_MIS_R & (uint32_t)(1U<<(SW1%8))) /* check if interrupt causes by PF4/SW1*/
    {
       /*stop the motors*/
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW1%8));
        start_flag = 0;
        elapsed_time_S = 0;
        car_Stop();
        GPTM_Disable(GPTM_Timer0.timer);
        DIO_WritePin(PF1, HIGH);
    }
    else if (GPIO_PORTF_MIS_R & (unsigned long)(1U<<(SW2%8))) /* check if interrupt causes by PF0/SW2 */
    {
        /*start the motors*/
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW2%8));
        start_flag = 1;
        /* Enable timer to start counting*/
        GPTM_Enable(GPTM_Timer0.timer);
        GPTM_TAILR_Value_Loud(GPTM_Timer0.timer, 16000000); /*Int for 1 second*/
        DIO_WritePin(PF1, LOW);
        DIO_WritePin(PF2, LOW);
    }
    else {
        /* Do nothing for MISRA */
    }
}

void LCD_Display(uint32_t temp, uint32_t ultra, int32_t ldr_diff, uint32_t elapsed_time)
{
    ldr_diff = abs(ldr_diff);

    /*56ms*/
    LCD_SetCursor(0, 3);     /* 4ms */
    LCD_WriteNumber_2D(temp);   /* 4ms*2 */
    LCD_SetCursor(0, 12);
    LCD_WriteNumber_3D(ultra);
    LCD_SetCursor(1, 4);
    LCD_WriteNumber_4D(ldr_diff);
    LCD_SetCursor(1, 13);
    LCD_WriteNumber_2D(elapsed_time);

}

void system_config(){
    /******************** System Configuration ********************/

    // Create the queues
    ultrasonic_Queue = xQueueCreate(QUEUE_LENGTH, sizeof(uint32_t));
    ldr_Diff_Queue = xQueueCreate(QUEUE_LENGTH, sizeof(uint32_t));

    /*********** Hardware Initialization (START) ************/
        __asm(" CPSIE  I");

        DIO_PORT_Init(PORTF);

        DIO_InitPin(SW1, INLLUP);
        DIO_InitPin(SW2, INLLUP);

        DIO_InitPin(PF1, OUTPUT);
        DIO_InitPin(PF3, OUTPUT);
        Interrupt_Edge_InitPin(SW1, LOW_EDGE);
        Interrupt_Edge_InitPin(SW2, LOW_EDGE);


        /* Timer0 initialization for time elapsed measurement */
        GPTM_Init(&GPTM_Timer0);

        /*** Motors ***/
        motors_Init();

        /*** LDRs Init ***/
        LDR_Right_Init();
        LDR_Left_Init();

        /*** Temperature Sensor ***/
        ADC_Init_Temperature(ADC_Base_0, CH_0);

        /*** UltraSonic Init ***/
        ultraSonic_Init(TRIG_PIN, ECHO_PIN);

        /*** LCD ***/
        /* Initialize LCD and all its connected pins*/
        LCD_Init();

        /*********** Hardware Initialization (END) ************/

    /******************** System Configuration ********************/
}

/************ Tasks ************/

/**
 * @brief Task 1 function that performs LDRs readings,
 *        and swings the car based on the LDR.s differences.
 */
void Task_1_LDR(void* p)
{

    TickType_t  pxPreviousWakeTime;
    pxPreviousWakeTime = xTaskGetTickCount();


    uint32_t ldr_left_Read ;
    uint32_t ldr_right_Read ;
    int32_t ldrs_Difference;

    for(;;)
    {
        pxPreviousWakeTime = xTaskGetTickCount();

        /* Read left LDR, and right LDR values */
        ldr_left_Read = LDR_Left_Read();        /*>1ms*/
        ldr_right_Read = LDR_Right_Read();      /*>1ms*/
        ldrs_Difference = ldr_left_Read - ldr_right_Read;

        /* Send data to the LDR queue */
        xQueueSend(ldr_Diff_Queue, &ldrs_Difference, portMAX_DELAY);

        pxPreviousWakeTime = xTaskGetTickCount();
        vTaskDelayUntil(&pxPreviousWakeTime, 5);
    }


}

/**
 * @brief Task 2 function that displays temperature, LDRs, ultraSonic
 *        and time elapsed readings values on an LCD.
 */
void Task_2_LCD_Display(void* p)
{
    TickType_t  pxPreviousWakeTime;
    pxPreviousWakeTime = xTaskGetTickCount();
    uint32_t temperature_Read;
    uint32_t ultrasonic_Data;
    uint32_t ldr_Data;

    for(;;)
    {
        pxPreviousWakeTime = xTaskGetTickCount();

        /* Read temperature value */
        temperature_Read = Temperature_Read(CH_0);      /*>1ms*/
        /* Receive ultrasonic data from the queue*/
        xQueueReceive(ultrasonic_Queue, &ultrasonic_Data, portMAX_DELAY);

        /* Receive LDR data from the queue*/
        xQueueReceive(ldr_Diff_Queue, &ldr_Data, portMAX_DELAY);


        /* Display temperature, ultraSonic_read, LDR difference on LCD */
        LCD_Display(temperature_Read, ultrasonic_Data, ldr_Data, elapsed_time_S);    /* 56ms / max = 128ms*/
//        taskYIELD();
        TickType_t _pxPreviousWakeTime = xTaskGetTickCount();
        vTaskDelayUntil(&pxPreviousWakeTime, 120);
    }

}


/**
 * @brief Task 3 function that performs ultraSonic reading,
 *        avoid obstacles if ultraSonic_Read_CM <= 10 CM.
 */
void Task_3_UltraSonic(void* p)
{
    TickType_t  pxPreviousWakeTime;
    pxPreviousWakeTime = xTaskGetTickCount();

    uint32_t uiultraSonic_read;

    for(;;)
    {
        pxPreviousWakeTime = xTaskGetTickCount();
        /* Read ultraSonic value */
        uiultraSonic_read = ultraSonic_Read_CM();     /*max time 2.63ms approximately*/
        /* Send data to the ultrasonic queue */
        xQueueSend(ultrasonic_Queue, &uiultraSonic_read, portMAX_DELAY);


        pxPreviousWakeTime = xTaskGetTickCount();
        vTaskDelayUntil(&pxPreviousWakeTime, 5);
    }

}

/**
 * @brief Task 4 function that performs car moving,
 *        avoid obstacles if ultraSonic_Read_CM <= 10 CM.
 *        and swings the car based on the LDR.s differences.
 */
void Task_4_MOTORS(void* p)
{
    TickType_t  pxPreviousWakeTime;
    pxPreviousWakeTime = xTaskGetTickCount();

    uint32_t uiultraSonic_read;
    int32_t ldrs_Difference;

    for(;;)
    {
        pxPreviousWakeTime = xTaskGetTickCount();

        if(start_flag)
        {
            /* Receive ultrasonic data from the queue*/
            xQueueReceive(ultrasonic_Queue, &uiultraSonic_read, portMAX_DELAY);
            /* Receive LDR data from the queue*/
            xQueueReceive(ldr_Diff_Queue, &ldrs_Difference, portMAX_DELAY);

            if(uiultraSonic_read <= max_Obestacle_Distance && uiultraSonic_read > 1)
            {
                /* Move backward then rotate 90 degree */
                /* motors fun here */
                move_Backward(SPEED);
                vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.4);
                turn_Car(RIGHT);
                vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.8);
            }
            else if(ldrs_Difference > 200 ){
                /* Swing Right */
                /* motors fun here */
                turn_Car(RIGHT);
                vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.01);
            }
            else if(ldrs_Difference < -200 ){
                /* Swing Left */
                /* motors fun here */
                turn_Car(LEFT);
                vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.01);
            }
            else
            {
                /* otherwise, stay moving the car forward */
                move_Forward(SPEED);
            }
            pxPreviousWakeTime = xTaskGetTickCount();
            vTaskDelayUntil(&pxPreviousWakeTime, 5);
            taskYIELD();
        }
        else
        {
            /* */
            vTaskDelayUntil(&pxPreviousWakeTime, 50);
        }


    }

}



/***************************************/
