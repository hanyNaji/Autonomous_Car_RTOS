

/**
 * main.c
 */
#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include"GPIO_Interface.h"
#include"Timer_Interface.h"
#include"tm4c123gh6pm.h"


 __asm( " cpsie  i");  // Enable global Interrupt
int main(void)
{
        GPIO_void_Init();
        GPIO_voidSetPinDirection(GPIOF_PORT, PIN1, GPIO_OUTPUT);
        GPIO_voidSetPortValue(GPIOF_PORT, LOW);

        GPIO_voidSetPinDirection(GPIOF_PORT, PIN4, GPIO_INPUT);/* switch1 */
        GPIO_voidSetPinDirection(GPIOF_PORT, PIN0, GPIO_INPUT);/* switch2 */
        GPIO_voidSetPinPullUp(GPIOF_PORT, PIN4);
        GPIO_voidSetPinPullUp(GPIOF_PORT, PIN0);
        Interrupt_Edge_InitPin(GPIOF_PORT,PIN0,0);
        NVIC_EN0_R |= (1U<<19);
       // GPIO_voidSetPinValue(GPIOF_PORT, PIN1, HIGH);
        while(1)
        {
            if (GPIO_u8GetPinValue(GPIOF_PORT, PIN4)==0){   /* start */
                while(GPIO_u8GetPinValue(GPIOF_PORT, PIN4)==0);   // switch 2
                Timer_voidInit();
                GPIO_voidSetPinValue(GPIOF_PORT, PIN1, GPIO_HIGH);
                GPIO_voidSetPinValue(GPIOF_PORT, PIN3, GPIO_LOW);
        }
}

}

void Intimer0fHandler(void)
{
    TIMER0_ICR_R |=(1U<<0);
    GPIO_voidSetPinValue(GPIOF_PORT, PIN1, LOW);
//   GPIO_PORTF_DATA_R ^= (1U<<1);

}


void PORTF_Interrupt(void)
{

    /*  Stop interrupt */
    GPIO_voidSetPinValue(GPIOF_PORT, PIN1,GPIO_LOW);
    GPIO_voidSetPinValue(GPIOF_PORT, PIN3, GPIO_HIGH);
    INSERT_BIT(GPIO_PORTF_ICR_R, PIN0, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)

}








