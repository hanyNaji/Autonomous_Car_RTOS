/*
 * scheduler.c
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */


#include <scheduler/scheduler.h>
#include "MCAL/systick/systick.h"



task_Control_Struct task_Control_Block[NUM_OF_TASKS];


void tasks_scheduler(void)
{
    SysTick_Init(ST_INTDISABLE);
    SysTick_Enable();
    uint8_t index =0;

    for (index = 0; index < NUM_OF_TASKS; index++) {

        SysTick_Reload_ms(task_Control_Block[index].ms_task_period);

        while( !SysTick_Read_COUNT() )
        {
            task_Control_Block[index].task_ptr();
        }
        if(index == NUM_OF_TASKS -1)
        {
            index = 0;
        }

    }

}


void create_task(void (*task)(), uint32_t ms_periodicity )
{
    static uint8_t index=0;
    if(index == (NUM_OF_TASKS -1))
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




