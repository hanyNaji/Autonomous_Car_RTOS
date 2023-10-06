/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */

/***************** Includes ****************/

#include "app/app.h"




/* Global variables */
uint32_t g_ui32CPUUsage;
uint32_t g_ulSystemClock; // System clock speed


/* The error routine that is called if the driver library or freeRTOS encounters an error.*/
#ifdef DEBUG
void __error__(char *nombrefich, uint32_t linea){
    while(1);
}
#endif

/********** Events links for FreeRTOS **********/

/* Stack overflow detected */
void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName){
    while(1);
}

/* CPU monitoring every system tick */
void vApplicationTickHook( void ){
    static uint8_t count = 0;
    if (++count == 10){
        g_ui32CPUUsage = CPUUsageTick();
        count = 0;
    }
}

/* Executes when Idle task runs */
void vApplicationIdleHook (void){
    SysCtlSleep();
}
/* Executes when Idle task runs */
void vApplicationMallocFailedHook (void){
    while(1);
}


/**
 * main.c
 */
void main(void)
{
    /*** System Configurations ***/
    system_config();

    /*********** Tasks Initialization (START) ************/

    if((xTaskCreate(Task_3_UltraSonic, (portCHAR *)"Task_3_UltraSonic", 128, NULL, 3, NULL) != pdTRUE)){
        while(1){}
    }

    if((xTaskCreate(Task_1_LDR, (portCHAR *)"Task_1_LDR", 128, NULL, 2, NULL) != pdTRUE)){
        while(1){}
    }

    if((xTaskCreate(Task_2_LCD_Display, (portCHAR *)"Task_2_LCD_Display", 128, NULL, 2, NULL) != pdTRUE)){
        while(1){}
    }

    if((xTaskCreate(Task_4_MOTORS, (portCHAR *)"Task_4_MOTORS", 128, NULL, 4, NULL) != pdTRUE)){
        while(1){}
    }



    /*********** Tasks Initialization (END) ************/


    /*********** Scheduler (START) ************/
    vTaskStartScheduler();  /* Start scheduler, RTOS enables interruptions here. */

    /*********** Scheduler (END) ************/


    while(812)
    {

    }
}





