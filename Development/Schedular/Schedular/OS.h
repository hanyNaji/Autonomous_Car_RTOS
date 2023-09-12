


#ifndef OS_H_
#define OS_H_
#include "Std_types.h"
#define MAX_NUM_OF_TASKS 	((u8)3)
#define HYPER_PERIOD 		((u8)6)



typedef void (*fncPtr)(void);           /**< Function pointer for registering tasks. */


typedef enum
{
	BLOCKED,
	READY,
	SUSPENDED
} OS_state;


/*Task Control Block*/
typedef struct
{
	fncPtr		function;
	u8 			task_periodicity;
	OS_state	task_state;
	u8 			Task_counter;
} OS_struct;


typedef enum
{
	OK_task,
	NOK_NULL_POINTER,
	NOK_COUNT_LIMIT,
	NOK_TIME_LIMIT,
	NOK_UNKNOWN
} OS_feedback;


OS_feedback OS_TaskCreate(fncPtr task, u8 default_time_burst, OS_state default_state);

void OS_Task_Handler(void);

void OS_TaskExecution(void);

void milliesecond(void);




#endif /* OS_H_ */