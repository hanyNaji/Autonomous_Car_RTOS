/*
 * Interrupt_Proram.c
 *
 *  Created on: ???/???/????
 *      Author: walee
 */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include <tm4c123gh6pm.h>

#include "Interrupt_Interface.h"
#include "Interrupt_Private.h"



void ISR_void_Init(void)
{

    GPIO_PORTF_IM_R = 0x00;
    GPIO_PORTF_IS_R = 0x00;
    GPIO_PORTF_IBE_R = 0x00;
    GPIO_PORTF_RIS_R = 0x00;
    GPIO_PORTF_IM_R = 0xFF;
    CLR_BIT(GPIO_PORTF_IS_R,4);
    CLR_BIT(GPIO_PORTF_IEV_R,4);
    SET_BIT(GPIO_PORTF_ICR_R,4);
    SET_BIT(GPIO_PORTF_IM_R,4);
    CLR_BIT(GPIO_PORTF_IS_R,0);
    CLR_BIT(GPIO_PORTF_IEV_R,0);
        SET_BIT(GPIO_PORTF_ICR_R,0);
        SET_BIT(GPIO_PORTF_IM_R,0);

   SET_BIT(NVIC_EN0_R,30);


}

