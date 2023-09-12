/*
 * GPIO_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#ifndef GPIO_DRIVER_GPIO_INTERFACE_H_
#define GPIO_DRIVER_GPIO_INTERFACE_H_



/* Macros Of Port */
#define  GPIOA_PORT         0
#define  GPIOB_PORT         1
#define  GPIOC_PORT         2
#define  GPIOD_PORT         3
#define  GPIOE_PORT         4
#define  GPIOF_PORT         5


/* Macros Of Pins */
#define  PIN0               0
#define  PIN1               1
#define  PIN2               2
#define  PIN3               3
#define  PIN4               4
#define  PIN5               5
#define  PIN6               6
#define  PIN7               7

#define  GPIO_HIGH          1      // logic 1
#define  GPIO_LOW           0      // logic 0

#define  GPIO_OUTPUT        1      // direction output
#define  GPIO_INPUT         0      // direction input


void GPIO_void_Init(void);

void GPIO_voidSetPinDirection(u8 cpy_u8PortNumber ,u8 cpy_u8PinNo,u8 cpy_u8Direction);
void GPIO_voidSetPinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNo, u8 cpy_u8value);
u8   GPIO_u8GetPinValue(u8 cpy_u8PortNumber , u8 cpy_u8PinNo);


void GPIO_voidSetPortDirection(u8 cpy_u8PortNumber,u8 cpy_u8Direction);
void GPIO_voidSetPortValue(u8 cpy_u8PortNumber,u8 cpy_u8value);
u8   GPIO_u8GetPortValue(u8 cpy_u8PortNumber);

void GPIO_voidSetPortPullUp(u8 cpy_u8PortNumber);
void GPIO_voidSetPortPullDown(u8 cpy_u8PortNumber);

void GPIO_voidSetPinPullUp(u8 cpy_u8PortNumber,u8 cpy_u8PinNo);
void GPIO_voidSetPinPullDown(u8 cpy_u8PortNumber,u8 cpy_u8PinNo);

void GPIO_voidTogglePinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNo);
void Interrupt_Edge_InitPin(u8 cpy_u8PortNumber, u8 cpy_u8PinNo, u8 edge);


#endif /* GPIO_DRIVER_GPIO_INTERFACE_H_ */
