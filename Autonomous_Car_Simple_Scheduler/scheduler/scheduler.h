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


/**
 * @brief Initializes and manages a simple task scheduler.
 *        This scheduler runs a set of tasks in a round-robin fashion at specified time intervals.
 */
void tasks_scheduler(void);

/**
 * @brief Creates a new task with a specified function and periodicity.
 *
 * @param task Pointer to the task function.
 * @param ms_periodicity Time interval (in milliseconds) at which the task should run.
 */
void create_task(void (*task)(), uint32_t ms_periodicity);




#endif /* SCHEDULER_SCHEDULER_H_ */
