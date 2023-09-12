/*
 * GPIO_Private.h
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#ifndef GPIO_DRIVER_GPIO_PRIVATE_H_
#define GPIO_DRIVER_GPIO_PRIVATE_H_


// PORTA

#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_R        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))


// PORTB

#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_R        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))


// PORTC

#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_PUR_R        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_R        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_R       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile unsigned long *)0x40006524))

// PORTD

#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))


// PORTE

#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_R        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))

// PORTF

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))

// macros for PORTA

#define  PORTA_DATA            GPIO_PORTA_DATA_R
#define  PORTA_DIR             GPIO_PORTA_DIR_R
#define  PORTA_PULLUP          GPIO_PORTA_PUR_R
#define  PORTA_PULLDOWN        GPIO_PORTA_PDR_R
#define  PORTA_DENABLE         GPIO_PORTA_DEN_R
#define  PORTA_LOCK            GPIO_PORTA_LOCK_R
#define  PORTA_CR              GPIO_PORTA_CR_R

// macros for PORTB

#define  PORTB_DATA            GPIO_PORTB_DATA_R
#define  PORTB_DIR             GPIO_PORTB_DIR_R
#define  PORTB_PULLUP          GPIO_PORTB_PUR_R
#define  PORTB_PULLDOWN        GPIO_PORTB_PDR_R
#define  PORTB_DENABLE         GPIO_PORTB_DEN_R
#define  PORTB_LOCK            GPIO_PORTB_LOCK_R
#define  PORTB_CR              GPIO_PORTB_CR_R

// macros for PORTC

#define  PORTC_DATA            GPIO_PORTC_DATA_R
#define  PORTC_DIR             GPIO_PORTC_DIR_R
#define  PORTC_PULLUP          GPIO_PORTC_PUR_R
#define  PORTC_PULLDOWN        GPIO_PORTC_PDR_R
#define  PORTC_DENABLE         GPIO_PORTC_DEN_R
#define  PORTC_LOCK            GPIO_PORTC_LOCK_R
#define  PORTC_CR              GPIO_PORTC_CR_R



// macros for PORTD

#define  PORTD_DATA            GPIO_PORTD_DATA_R
#define  PORTD_DIR             GPIO_PORTD_DIR_R
#define  PORTD_PULLUP          GPIO_PORTD_PUR_R
#define  PORTD_PULLDOWN        GPIO_PORTD_PDR_R
#define  PORTD_DENABLE         GPIO_PORTD_DEN_R
#define  PORTD_LOCK            GPIO_PORTD_LOCK_R
#define  PORTD_CR              GPIO_PORTD_CR_R



// macros for PORTE

#define  PORTE_DATA            GPIO_PORTE_DATA_R
#define  PORTE_DIR             GPIO_PORTE_DIR_R
#define  PORTE_PULLUP          GPIO_PORTE_PUR_R
#define  PORTE_PULLDOWN        GPIO_PORTE_PDR_R
#define  PORTE_DENABLE         GPIO_PORTE_DEN_R
#define  PORTE_LOCK            GPIO_PORTE_LOCK_R
#define  PORTE_CR              GPIO_PORTE_CR_R



// macros for PORTF

#define  PORTF_DATA            GPIO_PORTF_DATA_R
#define  PORTF_DIR             GPIO_PORTF_DIR_R
#define  PORTF_PULLUP          GPIO_PORTF_PUR_R
#define  PORTF_PULLDOWN        GPIO_PORTF_PDR_R
#define  PORTF_DENABLE         GPIO_PORTF_DEN_R
#define  PORTF_LOCK            GPIO_PORTF_LOCK_R
#define  PORTF_CR              GPIO_PORTF_CR_R





#endif /* GPIO_DRIVER_GPIO_PRIVATE_H_ */
