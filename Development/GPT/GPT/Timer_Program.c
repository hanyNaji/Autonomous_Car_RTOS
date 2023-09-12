/*
 * Timer_Program.c
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
#include "Timer_Interface.h"
#include "Timer_Config.h"

#define  PERIODIC_MODE 0x1
#define  TAMR_FIELD 0

void Timer_voidInit(void)
{

       SYSCTL_RCGCTIMER_R  = 0x01;
//    1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
//    any changes.
       CLR_BIT(TIMER0_CTL_R,0);

//    2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.
       TIMER0_CFG_R = 0x00000000;
//    3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
       TIMER0_TAMR_R |= (PERIODIC_MODE<<TAMR_FIELD); // Periodic mode
//    a. Write a value of 0x1 for One-Shot mode.
//    b. Write a value of 0x2 for Periodic mode.

//    4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
//    to select whether to capture the value of the free-running timer at time-out, use an external
//    trigger to start counting, configure an additional trigger or interrupt, and count up or down.

      TIMER0_TAMR_R &=~ (1U<<4);


//    5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
       //Example: Toggle led 0.5
       // 16 MHZ -----> 1 sec
       // ???? -------> 0.5 sec
       // 8000000 counts
       TIMER0_TAILR_R =5*(16000000U-1);

//    6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
//    (GPTMIMR).
       TIMER0_IMR_R = 0x01;


//    7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
       TIMER0_CTL_R |=(1U<<0);

//    8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
//    the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
//    Register (GPTMICR).
//     TIMER0_ICR_R = 0x01;

}

void Timer_voidPeriodic(u32 ticks_count)
{
    TIMER0_TAILR_R= ticks_count -1;

}



