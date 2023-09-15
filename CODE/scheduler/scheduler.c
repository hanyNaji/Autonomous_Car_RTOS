/*
 * scheduler.c
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */


#include <scheduler/scheduler.h>
#include "MCAL/systick/systick.h"
#include "MCAL/Tiva_DIO/Tiva_DIO.h"



task_Control_Struct task_Control_Block[NUM_OF_TASKS];


/**
 * @brief Initializes and manages a simple task scheduler.
 *        This scheduler runs a set of tasks in a round-robin fashion at specified time intervals.
 */
void tasks_scheduler(void)
{
    SysTick_Init(ST_INTDISABLE);
    uint8_t index =0;

    while(812)
    {
        SysTick_Reload_ms(task_Control_Block[index].ms_task_period);
        SysTick_Enable();

        while( !SysTick_Read_COUNT() )
        {
            task_Control_Block[index].task_ptr();
            _delay_ms(1);
        }
        _delay_ms(10);

        index++;
        if(index == NUM_OF_TASKS)
        {
            index = 0;
        }
    }

}


/**
 * @brief Creates a new task with a specified function and periodicity.
 *
 * @param task Pointer to the task function.
 * @param ms_periodicity Time interval (in milliseconds) at which the task should run.
 */
void create_task(void (*task)(), uint32_t ms_periodicity )
{
    static uint8_t index=0;
    if(index >= (NUM_OF_TASKS))
    {
        return;
    }
    else
    {
        task_Control_Block[index].task_ptr = task;
        task_Control_Block[index].ms_task_period = ms_periodicity;
        index +=1;
    }
}




