/*
 * TASK.c
 *
 */ 
/*#include "TASK.h"*/
#include <util/delay.h>
#include "MemMap.h"
#include "Std_types.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "Timer.h"
#include "Timers_services.h"


void Task_2S_Blink(void)
{
		static flag=0;
		if(flag==0){
			DIO_WritePin(PIND2,HIGH);
			flag=1;
		}
		else{
			DIO_WritePin(PIND2,LOW);
			flag=0;
			
		}
}


void Task_1S_LcdUpdate(void)
{
	static u16 u16Seconds = 2;


	LCD_SetCursor(0,10);
	LCD_WriteNumber(u16Seconds);
	u16Seconds+=2;

}

void Task_3S_Blink(void)
{
	static flag=0;
	if(flag==0){
	  DIO_WritePin(PIND4,HIGH);
	  flag=1;
	}
	else{
		DIO_WritePin(PIND4,LOW);
		flag=0;
	  
}
}
