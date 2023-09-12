/*
 * systick.h
 *
 *  Created on: Aug 31, 2023
 *      Author: hany Nagy
 */

#ifndef SysTick_SysTick_H_
#define SysTick_SysTick_H_



#include "MCAL/Tiva_DIO/Tiva_DIO.h"



typedef enum
{
    ST_INTDISABLE = 0,
    ST_INTENABLE
} ST_CTRL_INTEN_Type;




/**************************************************************/
/***************            SysTick             ***************/
/**************************************************************/


void SysTick_Init(ST_CTRL_INTEN_Type INTEN);

void SysTick_Disable(void);

void SysTick_Enable(void);

uint8_t SysTick_Read_COUNT(void);

uint32_t SysTick_Read_ms(void);

void SysTick_Reload_ms(uint32_t value);


#endif /* SysTick_SysTick_H_ */
