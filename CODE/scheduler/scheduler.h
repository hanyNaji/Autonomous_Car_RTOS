/*
 * scheduler.h
 *
 *  Created on: Sep 9, 2023
 *      Author: hany Nagy
 */

#ifndef SCHEDULER_SCHEDULER_H_
#define SCHEDULER_SCHEDULER_H_


#include "utils/typedefs.h"



#define NUM_OF_TASKS    3U



typedef struct{
    void(*task_ptr)();
    uint32_t ms_task_period;
}task_Control_Struct;


void tasks_scheduler(void);


void create_task (void (*task)(), uint32_t ms_periodicity );



#endif /* SCHEDULER_SCHEDULER_H_ */
