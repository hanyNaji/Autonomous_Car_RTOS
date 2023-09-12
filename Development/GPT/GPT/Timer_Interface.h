/*
 * Timer_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#ifndef TIMER_DRIVER_TIMER_INTERFACE_H_
#define TIMER_DRIVER_TIMER_INTERFACE_H_


void Timer_voidInit(void);
void Timer_voidPeriodic(u32 ticks_count);
void Timer_voidOneshot(void);

#endif /* TIMER_DRIVER_TIMER_INTERFACE_H_ */
