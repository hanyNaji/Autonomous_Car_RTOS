/*
 *  Tiva_DIO.h
 *
 *  Created on: Aug 13, 2023
 *  Author: hany nagy
 */

#ifndef TIVA_DIO_TIVA_DIO_H_
#define TIVA_DIO_TIVA_DIO_H_

#include <stdint.h>

/*** Enumerations ***/

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTS_NUM
} PORT_Name_Type;

typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} DIO_Pin_type;

typedef enum
{
    PA0=0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,
    PB0,
    PB1,
    PB2,
    PB3,
    PB4,
    PB5,
    PB6,
    PB7,
    PC0,
    PC1,
    PC2,
    PC3,
    PC4,
    PC5,
    PC6,
    PC7,
    PD0,
    PD1,
    PD2,
    PD3,
    PD4,
    PD5,
    PD6,
    PD7,
    PE0,
    PE1,
    PE2,
    PE3,
    PE4,
    PE5,
    PE6,
    PE7,
    PF0,
    PF1,
    PF2,
    PF3,
    PF4,
    PF5,
    PF6,
    PF7,
    TOTAL_PINS
} DIO_AllPINS_TYPE;

typedef enum
{
    OUTPUT,
    INFREE,
    INLLUP
} DIO_PinStatus_type;

typedef enum
{
    LOW = 0,
    HIGH
} Output_Value_Type;

typedef enum
{
    LOW_EDGE = 0,
    HIGH_EDGE
} Int_Edge_Type;


/*********** Function Prototypes *************/


/**************************************************************/
/***************       DATA_BITS REGISTER       ***************/
/**************************************************************/

/**
 * @brief Writes a logical HIGH to a specific bit in a specified port's DATA_BITS register.
 */
void WriteDataBIT(PORT_Name_Type port, uint8_t bit);

/**
 * @brief Writes a value (HIGH or LOW) to a specified set of bits in a specified port's DATA_BITS register.
 */
void WriteDataBITS(PORT_Name_Type port, uint8_t bits, uint8_t value);

/**
 * @brief Clears a specific bit in a specified port's DATA_BITS register.
 */
void ClearDataBIT(PORT_Name_Type port, uint8_t bit);

/**
 * @brief Reads the value of a specific bit in a specified port's DATA_BITS register.
 *
 * @return The value of the specified bit (HIGH or LOW).
 */
uint8_t ReadDataBIT(PORT_Name_Type port, uint8_t bit);


/**************************************************************/
/***************           GPIO_PORTS           ***************/
/**************************************************************/

/**
 * @brief Initializes a specific pin with the specified status (OUTPUT, INFREE, or INLLUP).
 */
void DIO_InitPin(DIO_AllPINS_TYPE pin_num, DIO_PinStatus_type status);

/**
 * @brief Writes a value (HIGH or LOW) to a specific pin.
 */
void DIO_WritePin(DIO_AllPINS_TYPE pin_num, Output_Value_Type value);

/**
 * @brief Reads the value (HIGH or LOW) of a specific pin.
 *
 * @return The value of the specified pin.
 */
Output_Value_Type DIO_ReadPin(DIO_AllPINS_TYPE pin_num);

/**
 * @brief Toggles the value of a specific pin (from HIGH to LOW or vice versa).
 */
void DIO_TogglePin(DIO_AllPINS_TYPE pin_num);

/**
 * @brief Initializes a specific port.
 */
void DIO_PORT_Init(PORT_Name_Type port);

/**
 * @brief Writes a value (0-255) to a specific port's pins.
 */
void DIO_WritePort(PORT_Name_Type Port, uint8_t value);

/**
 * @brief Reads the value of all pins in a specific port.
 *
 * @return The value of all pins in the specified port (0-255).
 */
uint8_t DIO_ReadPort(PORT_Name_Type port);

/**************************************************************/
/***************        INTERRUPT_PORTS         ***************/
/**************************************************************/

/**
 * @brief Initializes a specific pin with the specified interrupt edge type (LOW_EDGE or HIGH_EDGE).
 */
void Interrupt_Edge_InitPin(DIO_AllPINS_TYPE pin_num, Int_Edge_Type edge);




/************* UTILS **************/

void _delay_ms(uint16_t n);
void _delay_us( uint16_t n);


#endif /* TIVA_DIO_TIVA_DIO_H_ */
