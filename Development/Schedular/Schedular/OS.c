
#include "OS.h"
#include "Std_types.h"

static u8 counter=0;
static OS_struct arr[MAX_NUM_OF_TASKS];
OS_feedback OS_TaskCreate(fncPtr function, u8 periodicty, OS_state default_state){
	OS_feedback status=	NOK_UNKNOWN;
	
	if(counter>=MAX_NUM_OF_TASKS){
		status=NOK_COUNT_LIMIT;
        	}
	else if(function==NULLPTR){
	 	status =NOK_NULL_POINTER;
	    }
else if(periodicty>=HYPER_PERIOD){
	status=NOK_TIME_LIMIT;
       }
  else{
	arr[counter].function=function;
	arr[counter].task_periodicity=periodicty;
	arr[counter].task_state=default_state;
	arr[counter].Task_counter=1; // put it as initial value =1 to compare it with periodicity when it equal the periodicity it means the task is ready 
	status =OK_task;
 	counter++;
      }
	return status;
}


void OS_Task_Handler(void){
	
	for(int i=0;i<counter;i++){
		
		if(arr[i].task_state!=SUSPENDED){
		     if(arr[i].Task_counter>=arr[i].task_periodicity){
			arr[i].task_state=READY;
			arr[i].Task_counter=1;
			 }
		else{
			
			arr[i].Task_counter++;  //increase counter to met the periodicity 
			
	         }
		}
	}
}

// main work
// void OS_TaskExecution(void)
// {
// 	u8 task_id;
// 
// 	for(task_id = 0; task_id < counter; task_id++)
// 	{
// 		if(arr[task_id].task_state == READY)
// 		{
// 			arr[task_id].function();
// 			arr[task_id].task_state = BLOCKED;
// 		}
// 	}
// }
// 
// void OS_TaskExecution(void);
// 
// void milliesecond(void){
// 	static u16 counter=0;
// 	counter++;
// 	if(counter>=1000){
// 		OS_Task_Handler();
// 		counter=0;
// 		
// 	}
// 
// }
// void vInitEcu(void)
// {
// 	
// 	
// 	u8 str[] = {"Seconds: "};
// 	sei();
// 	DIO_Init();
// 	LCD_Init();
// 
// 	DIO_WritePin(PIND4,LOW);
// 	DIO_WritePin(PIND2,LOW);
// 	LCD_WriteString(str);
// }
// void Schedular_INIT(void){
// 	
// 	TIMER0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8);
// 	Timer0_OVF_SetCallBack(milliesecond);
// 
// 	TIMER0_OV_InterruptEnable();
// 	//create number of tasks
// 	
// 	OS_TaskCreate(Task_1S_LcdUpdate,1, BLOCKED)	;
// 	OS_TaskCreate(Task_2S_Blink,2,     BLOCKED) ;
// 	OS_TaskCreate(Task_3S_Blink,4,   BLOCKED)	;
// 	
// }
// int main()
// {
// 	vInitEcu();
// 	Schedular_INIT();
// 	while(1){
// 		
// 		OS_TaskExecution();
// 		
// 		
// 	}
// 
// }
