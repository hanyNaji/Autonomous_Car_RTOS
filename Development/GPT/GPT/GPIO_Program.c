/*
 * GPIO_Program.c
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"


#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"



void GPIO_void_Init(void)
{
        SYSCTL_RCGCGPIO_R |= 0x3F; // Enable Clock on the whole ports
        PORTA_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTA_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTA_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

        PORTB_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTB_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTB_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

        PORTC_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTC_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTC_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

        PORTD_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTD_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTD_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

        PORTE_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTE_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTE_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

        PORTF_LOCK = 0x4C4F434B; // UNLOCK the register to enable accessing
        PORTF_CR = 0xFF;   // the commit register to write on GPIODEN
        PORTF_DENABLE = 0xFF;  // Digital Enable Register to enable pins as Digital

}



void GPIO_voidSetPinDirection(u8 cpy_u8PortNumber ,u8 cpy_u8PinNo,u8 cpy_u8Direction)
{

    if (cpy_u8Direction == GPIO_OUTPUT) // OUTPUT
    {
        switch(cpy_u8PortNumber)
        {
        case GPIOA_PORT :
            SET_BIT(PORTA_DIR,cpy_u8PinNo);
            break;
        case GPIOB_PORT :
            SET_BIT(PORTB_DIR,cpy_u8PinNo);
            break;
        case GPIOC_PORT :
            SET_BIT(PORTC_DIR,cpy_u8PinNo);
            break;
        case GPIOD_PORT :
             SET_BIT(PORTD_DIR,cpy_u8PinNo);
             break;
        case GPIOE_PORT :
             SET_BIT(PORTE_DIR,cpy_u8PinNo);
             break;
        case GPIOF_PORT :
             SET_BIT(PORTF_DIR,cpy_u8PinNo);
             break;

        }

    }

    else if(cpy_u8Direction == GPIO_INPUT)
        {
        switch(cpy_u8PortNumber)
               {
               case GPIOA_PORT :
                   CLR_BIT(PORTA_DIR,cpy_u8PinNo);
                   break;
               case GPIOB_PORT :
                   CLR_BIT(PORTB_DIR,cpy_u8PinNo);
                   break;
               case GPIOC_PORT :
                   CLR_BIT(PORTC_DIR,cpy_u8PinNo);
                   break;
               case GPIOD_PORT :
                    CLR_BIT(PORTD_DIR,cpy_u8PinNo);
                    break;
               case GPIOE_PORT :
                    CLR_BIT(PORTE_DIR,cpy_u8PinNo);
                    break;
               case GPIOF_PORT :
                    CLR_BIT(PORTF_DIR,cpy_u8PinNo);
                    break;

               }

        }

}


void GPIO_voidSetPinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNo, u8 cpy_u8value)
{

    if (cpy_u8value == GPIO_HIGH)
        {
            switch(cpy_u8PortNumber)
            {
            case GPIOA_PORT :
                SET_BIT(PORTA_DATA,cpy_u8PinNo);
                break;
            case GPIOB_PORT :
                SET_BIT(PORTB_DATA,cpy_u8PinNo);
                break;
            case GPIOC_PORT :
                SET_BIT(PORTC_DATA,cpy_u8PinNo);
                break;
            case GPIOD_PORT :
                 SET_BIT(PORTD_DATA,cpy_u8PinNo);
                 break;
            case GPIOE_PORT :
                 SET_BIT(PORTE_DATA,cpy_u8PinNo);
                 break;
            case GPIOF_PORT :
                 SET_BIT(PORTF_DATA,cpy_u8PinNo);
                 break;

            }

        }

        else if(cpy_u8value == GPIO_LOW)
            {
            switch(cpy_u8PortNumber)
                   {
                   case GPIOA_PORT :
                       CLR_BIT(PORTA_DATA,cpy_u8PinNo);
                       break;
                   case GPIOB_PORT :
                       CLR_BIT(PORTB_DATA,cpy_u8PinNo);
                       break;
                   case GPIOC_PORT :
                       CLR_BIT(PORTC_DATA,cpy_u8PinNo);
                       break;
                   case GPIOD_PORT :
                        CLR_BIT(PORTD_DATA,cpy_u8PinNo);
                        break;
                   case GPIOE_PORT :
                        CLR_BIT(PORTE_DATA,cpy_u8PinNo);
                        break;
                   case GPIOF_PORT :
                        CLR_BIT(PORTF_DATA,cpy_u8PinNo);
                        break;

                   }

             }

}


u8   GPIO_u8GetPinValue(u8 cpy_u8PortNumber , u8 cpy_u8PinNo)
{

        u8 loc_u8get =0;

            switch(cpy_u8PortNumber)
            {
            case GPIOA_PORT:
                    loc_u8get = GET_BIT(PORTA_DATA,cpy_u8PinNo);
                    break;
                case GPIOB_PORT:
                    loc_u8get = GET_BIT(PORTB_DATA,cpy_u8PinNo);
                    break;
                case GPIOC_PORT:
                    loc_u8get = GET_BIT(PORTC_DATA,cpy_u8PinNo);
                    break;
                case GPIOD_PORT:
                    loc_u8get = GET_BIT(PORTD_DATA,cpy_u8PinNo);
                    break;
                case GPIOE_PORT:
                    loc_u8get = GET_BIT(PORTE_DATA,cpy_u8PinNo);
                    break;
                case GPIOF_PORT:
                    loc_u8get = GET_BIT(PORTF_DATA,cpy_u8PinNo);
                    break;
            }

           return loc_u8get;

}


void GPIO_voidSetPortDirection(u8 cpy_u8PortNumber,u8 cpy_u8Direction)
{
            if (cpy_u8Direction == GPIO_OUTPUT)  //  OUTPUT
            {
           switch(cpy_u8PortNumber)
           {
           case GPIOA_PORT :
              PORTA_DIR = 0xFF;
               break;
           case GPIOB_PORT :
               PORTB_DIR = 0xFF;
               break;
           case GPIOC_PORT :
               PORTC_DIR = 0xFF;
               break;
           case GPIOD_PORT :
               PORTD_DIR = 0xFF;
               break;
           case GPIOE_PORT :
               PORTE_DIR = 0xFF;
               break;
           case GPIOF_PORT :
               PORTF_DIR = 0xFF;
               break;

           }
          }

            else if (cpy_u8Direction == GPIO_INPUT)  // INPUT
                        {
                       switch(cpy_u8PortNumber)
                       {
                       case GPIOA_PORT :
                          PORTA_DIR = cpy_u8Direction;
                           break;
                       case GPIOB_PORT :
                           PORTB_DIR = cpy_u8Direction;
                           break;
                       case GPIOC_PORT :
                           PORTC_DIR = cpy_u8Direction;
                           break;
                       case GPIOD_PORT :
                           PORTD_DIR = cpy_u8Direction;
                           break;
                       case GPIOE_PORT :
                           PORTE_DIR = cpy_u8Direction;
                           break;
                       case GPIOF_PORT :
                           PORTF_DIR = cpy_u8Direction;
                           break;

                       }
                      }

}

void GPIO_voidSetPortValue(u8 cpy_u8PortNumber,u8 cpy_u8value)
{
//        if (cpy_u8value == GPIO_HIGH)
//        {
         switch(cpy_u8PortNumber)
               {
               case GPIOA_PORT :
                   PORTA_DATA  = cpy_u8value;
                   break;
               case GPIOB_PORT :
                   PORTB_DATA  = cpy_u8value;
                   break;
               case GPIOC_PORT :
                   PORTC_DATA  = cpy_u8value;
                   break;
               case GPIOD_PORT :
                   PORTD_DATA  = cpy_u8value;
                    break;
               case GPIOE_PORT :
                   PORTE_DATA  = cpy_u8value;
                    break;
               case GPIOF_PORT :
                   PORTF_DATA  = cpy_u8value;
                    break;

               }
//        }

//        else if (cpy_u8value == GPIO_LOW)
//               {
//                switch(cpy_u8PortNumber)
//                      {
//                      case GPIOA_PORT :
//                          PORTA_DATA  = 0;
//                          break;
//                      case GPIOB_PORT :
//                          PORTB_DATA  = 0;
//                          break;
//                      case GPIOC_PORT :
//                          PORTC_DATA  = 0;
//                          break;
//                      case GPIOD_PORT :
//                          PORTD_DATA  = 0;
//                           break;
//                      case GPIOE_PORT :
//                          PORTE_DATA  = 0;
//                           break;
//                      case GPIOF_PORT :
//                          PORTF_DATA  = 0;
//                           break;
//
//                      }
//               }

}

u8   GPIO_u8GetPortValue(u8 cpy_u8PortNumber)
{

         u8 loc_u8get =0;

        switch(cpy_u8PortNumber)
        {
            case GPIOA_PORT:
                loc_u8get = PORTA_DATA;
                break;
            case GPIOB_PORT:
                loc_u8get = PORTB_DATA;
                break;
            case GPIOC_PORT:
                loc_u8get = PORTC_DATA;
                break;
            case GPIOD_PORT:
                loc_u8get = PORTD_DATA;
                break;
            case GPIOE_PORT:
                loc_u8get = PORTE_DATA;
                break;
            case GPIOF_PORT:
                loc_u8get = PORTF_DATA;
                break;
        }

        return loc_u8get;
}

void GPIO_voidSetPortPullUp(u8 cpy_u8PortNumber)
{



}

void GPIO_voidSetPortPullDown(u8 cpy_u8PortNumber)
{



}


void GPIO_voidSetPinPullUp(u8 cpy_u8PortNumber,u8 cpy_u8PinNo)
{

             switch(cpy_u8PortNumber)
                     {
                        case GPIOA_PORT :
                            SET_BIT(PORTA_PULLUP,cpy_u8PinNo);
                            break;
                        case GPIOB_PORT :
                            SET_BIT(PORTB_PULLUP,cpy_u8PinNo);
                            break;
                        case GPIOC_PORT :
                            SET_BIT(PORTC_PULLUP,cpy_u8PinNo);
                            break;
                        case GPIOD_PORT :
                            SET_BIT(PORTD_PULLUP,cpy_u8PinNo);
                            break;
                        case GPIOE_PORT :
                            SET_BIT(PORTE_PULLUP,cpy_u8PinNo);
                            break;
                        case GPIOF_PORT :
                            SET_BIT(PORTF_PULLUP,cpy_u8PinNo);
                            break;

                     }


}


void GPIO_voidSetPinPullDown(u8 cpy_u8PortNumber,u8 cpy_u8PinNo)
{

                  switch(cpy_u8PortNumber)
                         {
                            case GPIOA_PORT :
                                SET_BIT(PORTA_PULLDOWN,cpy_u8PinNo);
                                break;
                            case GPIOB_PORT :
                                SET_BIT(PORTB_PULLDOWN,cpy_u8PinNo);
                                break;
                            case GPIOC_PORT :
                                SET_BIT(PORTC_PULLDOWN,cpy_u8PinNo);
                                break;
                            case GPIOD_PORT :
                                SET_BIT(PORTD_PULLDOWN,cpy_u8PinNo);
                                break;
                            case GPIOE_PORT :
                                SET_BIT(PORTE_PULLDOWN,cpy_u8PinNo);
                                break;
                            case GPIOF_PORT :
                                SET_BIT(PORTF_PULLDOWN,cpy_u8PinNo);
                                break;

                         }

}


void GPIO_voidTogglePinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNo)
{

         switch(cpy_u8PortNumber)
              {
              case GPIOA_PORT :
                  TOG_BIT(PORTA_DATA,cpy_u8PinNo);
                  break;
              case GPIOB_PORT :
                  TOG_BIT(PORTB_DATA,cpy_u8PinNo);
                  break;
              case GPIOC_PORT :
                  TOG_BIT(PORTC_DATA,cpy_u8PinNo);
                  break;
              case GPIOD_PORT :
                   TOG_BIT(PORTD_DATA,cpy_u8PinNo);
                   break;
              case GPIOE_PORT :
                   TOG_BIT(PORTE_DATA,cpy_u8PinNo);
                   break;
              case GPIOF_PORT :
                   TOG_BIT(PORTF_DATA,cpy_u8PinNo);
                   break;

              }


}


void Interrupt_Edge_InitPin(u8 cpy_u8PortNumber, u8 cpy_u8PinNo, u8 edge)
{
    switch (cpy_u8PortNumber)
    {
        case GPIOA_PORT:
            INSERT_BIT(NVIC_EN0_R, 0, 1);    // enable interrupt for port A (0 -> EN0)
            INSERT_BIT(GPIO_PORTA_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTA_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTA_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTA_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTA_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case GPIOB_PORT:
            INSERT_BIT(NVIC_EN0_R, 1, 1);    // enable interrupt for port B (1 -> EN0)
            INSERT_BIT(GPIO_PORTB_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTB_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTB_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTB_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTB_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case GPIOC_PORT:
            INSERT_BIT(NVIC_EN0_R, 2, 1);    // enable interrupt for port C (2 -> EN0)
            INSERT_BIT(GPIO_PORTC_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTC_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTC_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTC_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTC_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case GPIOD_PORT:
            INSERT_BIT(NVIC_EN0_R, 3, 1);    // enable interrupt for port D (3 -> EN0)
            INSERT_BIT(GPIO_PORTD_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTD_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTD_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTD_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTD_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case GPIOE_PORT:
            INSERT_BIT(NVIC_EN0_R, 4, 1);    // enable interrupt for port E (4 -> EN0)
            INSERT_BIT(GPIO_PORTE_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTE_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTE_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTE_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTE_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case GPIOF_PORT:
            INSERT_BIT(NVIC_EN0_R, 30, 1);    // enable interrupt for port f (30 -> EN0)
            INSERT_BIT(GPIO_PORTF_IS_R, cpy_u8PinNo, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTF_IBE_R, cpy_u8PinNo, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTF_IEV_R, cpy_u8PinNo, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTF_ICR_R, cpy_u8PinNo, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTF_IM_R, cpy_u8PinNo, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
    }

}

