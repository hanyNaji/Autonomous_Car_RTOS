
/***************** Includes ****************/
/*** MCAL ***/
/* DIO*/
/* GPTM*/
/* ADC */
#include <MCAL/Tiva_GPTM_Timers/Tiva_GPTM_Timers.h>
#include "MCAL/Tiva_DIO/Tiva_DIO.h"
#include "MCAL/Tiva_ADC/ADC.h"

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

/*** Application ***/
/* scheduler */
#include "scheduler/scheduler.h"


/******* #Defines - MACROs *******/

#define TASK_1_PERIOD   10U
#define TASK_2_PERIOD   45U
#define TASK_3_PERIOD   15U


#define RED_LED    PF1
#define BLUE_LED   PF2
#define GREEN_LED  PF3

#define SW1    PF4
#define SW2    PF0


/******* Global variables *******/
volatile uint8_t start_flag = 0;

uint32_t temperature_Read = 0;
uint32_t ldr_left_Read = 0;
uint32_t ldr_right_Read = 0;
int32_t ldrs_Difference = 0;
uint32_t ultraSonic_read = 0;

volatile uint8_t  elapsed_time_S ;        /* To calculate seconds of the stop watch */

GPTM_Struct GPTM_Timer0 = {
    TIMER0,           /* Timer type */
    0x00UL,             /* Pre-scale value */
    PERIODIC,            /* Timer mode */
    UNCONCAT,           /* Concatenation mode */
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

/********** Functions prototypes ***********/
void LCD_Display(uint32_t temp, uint32_t ultra, uint32_t ldr_diff, uint32_t elapsed_time);
void car_Stop(void);


/************ Interrupts ************/
void Int_Timer0A_Handler(void)
{
    TIMER0_ICR_R |=(1U<<0);

    if(elapsed_time_S==59U){
        elapsed_time_S = 0U;
        start_flag = 0;
        car_Stop();
        GPTM_Disable(GPTM_Timer0.timer);
    }
    else {
        elapsed_time_S++;
    }
}

/* GPIO PORTF Interrupt handler */
void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (uint32_t)(1U<<(SW1%8))) /* check if interrupt causes by PF4/SW1*/
    {
       /*stop the motors*/
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW1%8));
        start_flag = 0;
        car_Stop();
        GPTM_Disable(GPTM_Timer0.timer);
    }
    else if (GPIO_PORTF_MIS_R & (unsigned long)(1U<<(SW2%8))) /* check if interrupt causes by PF0/SW2 */
    {
        /*start the motors*/
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW2%8));
        start_flag = 1;
        /* Enable timer to start counting*/
        GPTM_Enable(GPTM_Timer0.timer);
        GPTM_TAILR_Value_Loud(GPTM_Timer0.timer, 16000000); /*Int for 1 second*/
    }
    else {
        /* Do nothing for MISRA */
    }
}


/************ Tasks ************/

/**
 * @brief Task 1 function that performs LDRs readings,
 *        and swings the car based on the LDR.s differences.
 */
void Task_1(void);
void Task_1(void)
{

    /* Read left LDR, and right LDR values */
    ldr_left_Read = LDR_Left_Read();        /*1ms*/
    ldr_right_Read = LDR_Right_Read();      /*1ms*/
    ldrs_Difference = ldr_left_Read - ldr_right_Read;

    if(start_flag)
    {
        if(ldrs_Difference > 150 ){
            /* Swing Right */
            /* motors fun here */
            turn_Car(RIGHT, ANGLE);
        }
        else if(ldrs_Difference < -150 ){
            /* Swing Left */
            /* motors fun here */
            turn_Car(LEFT, ANGLE);
        }
        else
        {
            /* otherwise, stay moving the car forward */
            move_Forward(SPEED/2);
        }
    }
    else
    {
        /* */
    }
}

/**
 * @brief Task 2 function that displays temperature, LDRs, ultraSonic
 *        and time elapsed readings values on an LCD.
 */
void Task_2(void);
void Task_2(void)
{
    /* Read temperature value */
    temperature_Read = Temperature_Read(CH_0);      /*1ms*/
    /* Read ultraSonic value */
    ultraSonic_read = ultraSonic_Read_CM();     /*max time 2.63ms*/

    /* Display temperature, ultraSonic_read, LDR difference on LCD */
    LCD_Display(temperature_Read, ultraSonic_read, ldrs_Difference, elapsed_time_S);    /*11.2ms / max = 13ms*/

}


/**
 * @brief Task 3 function that performs ultraSonic reading,
 *        avoid obstacles if ultraSonic_Read_CM <= 10 CM.
 */
void Task_3(void);
void Task_3(void)
{
    /* Read ultraSonic value */
    ultraSonic_read = ultraSonic_Read_CM();     /*max time 15ms approximately*/

    if(start_flag)
    {
        if(ultraSonic_read <= max_Obestacle_Distance){
            /* Move backward then rotate 90 degree */
            /* motors fun here */
            move_Backward(SPEED/2);
            _delay_ms(100);
            turn_Car(RIGHT, 90);
        }
        else
        {
            /* */
        }
    }
    else
    {
        /* */
    }
}



/**
 * main.c
 */

void main(void);
void main(void)
{
    /*********** Hardware Initialization (START) ************/
    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTB);
    DIO_PORT_Init(PORTC);
    DIO_PORT_Init(PORTF);

    DIO_InitPin(SW1, INLLUP);
    DIO_InitPin(SW2, INLLUP);
    Interrupt_Edge_InitPin(SW1, LOW_EDGE);
    Interrupt_Edge_InitPin(SW2, LOW_EDGE);

    /*** UltraSonic ***/
    ultraSonic_Init(TRIG_PIN, ECHO_PIN);

    /*** Motors ***/
    motors_Init();

    /*** LDRs ***/
    LDR_Right_Init();
    LDR_Left_Init();

    /*** Temperature Sensor ***/
    ADC_Init_Temperature(ADC_Base_0, CH_0);

    /*** LCD ***/
    /* Initialize LCD and all its connected pins*/
    LCD_Init();

    /* Timer0 initialization for time elapsed measurement */
    GPTM_Init(&GPTM_Timer0);

    /*********** Hardware Initialization (END) ************/


    /*********** Tasks Initialization (START) ************/
    create_task(Task_1, TASK_1_PERIOD);
    create_task(Task_2, TASK_2_PERIOD);
    create_task(Task_3, TASK_3_PERIOD);

    /*********** Tasks Initialization (END) ************/


    /*********** Scheduler (START) ************/
    tasks_scheduler();

    /*********** Scheduler (END) ************/


    while(812)
    {

    }
}


void LCD_Display(uint32_t temp, uint32_t ultra, uint32_t ldr_diff, uint32_t elapsed_time)
{
    /* 11.2 ms */
    LCD_SetCursor(0, 3);     /* 800us */
    LCD_WriteNumber_2D(temp);   /* 800us*2 */
    LCD_SetCursor(0, 12);     /* 800us */
    LCD_WriteNumber_3D(ultra);
    LCD_SetCursor(1, 5);
    LCD_WriteNumber_3D(ldr_diff);
    LCD_SetCursor(1, 13);     /* 800us */
    LCD_WriteNumber_2D(elapsed_time);
}


void car_Stop(void)
{
    DIO_WritePin(MOTOR1_CTL_1, LOW);
    DIO_WritePin(MOTOR1_CTL_2, LOW);
    DIO_WritePin(MOTOR2_CTL_1, LOW);
    DIO_WritePin(MOTOR2_CTL_2, LOW);
}

