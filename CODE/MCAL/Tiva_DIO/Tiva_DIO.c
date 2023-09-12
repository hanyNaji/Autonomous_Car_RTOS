/*
 * Tiva_DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: hany nagy
 */

#include "Tiva_DIO.h"


/****************** DATA_BITS REGISTER ******************/

/**
 * @brief Writes a logical HIGH to a specific bit in a specified port's DATA_BITS register.
 */
void WriteDataBIT(PORT_Name_Type port, uint8_t bit)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        default:
            break;
    }
}

/**
 * @brief Writes a value (HIGH or LOW) to a specified set of bits in a specified port's DATA_BITS register.
 */
void WriteDataBITS(PORT_Name_Type port, uint8_t bits, uint8_t value)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[bits] = value;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[bits] = value;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[bits] = value;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[bits] = value;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[bits] = value;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[bits] = value;
            break;
        default:
            break;
    }
}

/**
 * @brief Clears a specific bit in a specified port's DATA_BITS register.
 */
void ClearDataBIT(PORT_Name_Type port, uint8_t bit)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[1<<bit] = 0;
            break;
        default:
            break;
    }
}

/**
 * @brief Reads the value of a specific bit in a specified port's DATA_BITS register.
 *
 * @return The value of the specified bit (HIGH or LOW).
 */
uint8_t ReadDataBIT(PORT_Name_Type port, uint8_t bit)
{
    uint8_t readBit = 0;
    switch (port) {
        case PORTA:
            readBit = GPIO_PORTA_DATA_BITS_R[1<<bit];
            break;
        case PORTB:
            readBit = GPIO_PORTB_DATA_BITS_R[1<<bit];
            break;
        case PORTC:
            readBit = GPIO_PORTC_DATA_BITS_R[1<<bit];
            break;
        case PORTD:
            readBit = GPIO_PORTD_DATA_BITS_R[1<<bit];
            break;
        case PORTE:
            readBit = GPIO_PORTE_DATA_BITS_R[1<<bit];
            break;
        case PORTF:
            readBit = GPIO_PORTF_DATA_BITS_R[1<<bit];
            break;
        default:
            break;
    }
    return readBit;
}


/*********************** GPIO_PORTS **********************/

/**
 * @brief Initializes a specific port.
 */
void DIO_PORT_Init(PORT_Name_Type port)
{
    switch (port) {
        case PORTA:
            SYSCTL_RCGCGPIO_R |= 0x00000001;
            while(SYSCTL_RCGCGPIO_R & 0x00000001 == 0);
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            GPIO_PORTA_CR_R = 0xFF;
            break;
        case PORTB:
            SYSCTL_RCGCGPIO_R |= 0x00000002;
            while(SYSCTL_RCGCGPIO_R & 0x00000002 == 0);
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            GPIO_PORTB_CR_R = 0xFF;
            break;
        case PORTC:
            SYSCTL_RCGCGPIO_R |= 0x00000004;
            while(SYSCTL_RCGCGPIO_R & 0x00000004 == 0);
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            GPIO_PORTC_CR_R = 0xFF;
            break;
        case PORTD:
            SYSCTL_RCGCGPIO_R |= 0x00000008;
            while(SYSCTL_RCGCGPIO_R & 0x00000008 == 0);
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            GPIO_PORTD_CR_R = 0xFF;
            break;
        case PORTE:
            SYSCTL_RCGCGPIO_R |= 0x00000010;
            while(SYSCTL_RCGCGPIO_R & 0x00000010 == 0);
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            GPIO_PORTE_CR_R = 0xFF;
            break;
        case PORTF:
            SYSCTL_RCGCGPIO_R |= 0x00000020;
            while(SYSCTL_RCGCGPIO_R & 0x00000020 == 0);
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R = 0xFF;
            break;
        default:
            break;
    }
}

/***********************************/

/**
 * @brief Initializes a specific pin with the specified status (OUTPUT, INFREE, or INLLUP).
 */
void DIO_InitPin(DIO_AllPINS_TYPE pin ,DIO_PinStatus_type status)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;
    switch (status)
    {
        case OUTPUT:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
        case INFREE:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
        case INLLUP:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTA_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTB_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTC_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTD_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTE_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTF_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
    }

}

/**
 * @brief Writes a value (HIGH or LOW) to a specific pin.
 */
void DIO_WritePin(DIO_AllPINS_TYPE pin, Output_Value_Type value)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;
    switch (Port)
    {
        case PORTA:
            INSERT_BIT(GPIO_PORTA_DATA_R, pin_num, value);
            break;
        case PORTB:
            INSERT_BIT(GPIO_PORTB_DATA_R, pin_num, value);
            break;
        case PORTC:
            INSERT_BIT(GPIO_PORTC_DATA_R, pin_num, value);
            break;
        case PORTD:
            INSERT_BIT(GPIO_PORTD_DATA_R, pin_num, value);
            break;
        case PORTE:
            INSERT_BIT(GPIO_PORTE_DATA_R, pin_num, value);
            break;
        case PORTF:
            INSERT_BIT(GPIO_PORTF_DATA_R, pin_num, value);
            break;
    }
}

/**
 * @brief Reads the value (HIGH or LOW) of a specific pin.
 *
 * @return The value of the specified pin.
 */
Output_Value_Type DIO_ReadPin(DIO_AllPINS_TYPE pin)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;
    switch (Port)
    {
        case PORTA:
            return READ_BIT(GPIO_PORTA_DATA_R, pin_num);
            break;
        case PORTB:
            return READ_BIT(GPIO_PORTB_DATA_R, pin_num);
            break;
        case PORTC:
            return READ_BIT(GPIO_PORTC_DATA_R, pin_num);
            break;
        case PORTD:
            return READ_BIT(GPIO_PORTD_DATA_R, pin_num);
            break;
        case PORTE:
            return READ_BIT(GPIO_PORTE_DATA_R, pin_num);
            break;
        case PORTF:
            return READ_BIT(GPIO_PORTF_DATA_R, pin_num);
            break;
        default:
            return 0x00;
            break;
    }
}

/**
 * @brief Toggles the value of a specific pin (from HIGH to LOW or vice versa).
 */
void DIO_TogglePin(DIO_AllPINS_TYPE pin)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;

    switch(Port)
    {
        case PORTA:
            TOGGLE_BIT(GPIO_PORTA_DATA_R, pin_num);
            break;
        case PORTB:
            TOGGLE_BIT(GPIO_PORTB_DATA_R, pin_num);
            break;
        case PORTC:
            TOGGLE_BIT(GPIO_PORTC_DATA_R, pin_num);
            break;
        case PORTD:
            TOGGLE_BIT(GPIO_PORTD_DATA_R, pin_num);
            break;
        case PORTE:
            TOGGLE_BIT(GPIO_PORTE_DATA_R, pin_num);
            break;
        case PORTF:
            TOGGLE_BIT(GPIO_PORTF_DATA_R, pin_num);
            break;

    }


}

/**
 * @brief Writes a value (0-255) to a specific port's pins.
 */
void DIO_WritePort(PORT_Name_Type Port, uint8_t value)
{
    switch (Port)
    {
        case PORTA:
            GPIO_PORTA_DATA_R = value;
            break;
        case PORTB:
            GPIO_PORTB_DATA_R = value;
            break;
        case PORTC:
            GPIO_PORTC_DATA_R = value;
            break;
        case PORTD:
            GPIO_PORTD_DATA_R = value;
            break;
        case PORTE:
            GPIO_PORTE_DATA_R = value;
            break;
        case PORTF:
            GPIO_PORTF_DATA_R = value;
            break;
        default:
            break;
    }
}

//void DIO_Init(void)
//{
//    DIO_Pin_type i;
//    for (i=PINA0;i<TOTAL_PINS;i++)
//    {
//        DIO_InitPin(i,PinsStatusArray[i]);
//    }
//}


/************************************* INTERRUTPS **************************************/

/**
 * @brief Initializes a specific pin with the specified interrupt edge type (LOW_EDGE or HIGH_EDGE).
 */
void Interrupt_Edge_InitPin(DIO_AllPINS_TYPE pin, Int_Edge_Type edge)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;
    switch (Port)
    {
        case PORTA:
            INSERT_BIT(NVIC_EN0_R, 0, 1);    // enable interrupt for port f (0 -> EN0)
            INSERT_BIT(GPIO_PORTA_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTA_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTA_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTA_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTA_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTB:
            INSERT_BIT(NVIC_EN0_R, 1, 1);    // enable interrupt for port f (1 -> EN0)
            INSERT_BIT(GPIO_PORTB_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTB_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTB_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTB_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTB_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTC:
            INSERT_BIT(NVIC_EN0_R, 2, 1);    // enable interrupt for port f (2 -> EN0)
            INSERT_BIT(GPIO_PORTC_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTC_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTC_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTC_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTC_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTD:
            INSERT_BIT(NVIC_EN0_R, 3, 1);    // enable interrupt for port f (3 -> EN0)
            INSERT_BIT(GPIO_PORTD_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTD_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTD_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTD_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTD_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTE:
            INSERT_BIT(NVIC_EN0_R, 4, 1);    // enable interrupt for port f (4 -> EN0)
            INSERT_BIT(GPIO_PORTE_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTE_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTE_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTE_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTE_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTF:
            INSERT_BIT(NVIC_EN0_R, 30, 1);    // enable interrupt for port f (30 -> EN0)
            INSERT_BIT(GPIO_PORTF_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTF_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTF_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTF_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTF_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
    }

}



/************* UTILS **************/

void _delay_ms(uint16_t n)
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<3180;j++){};
}
void _delay_us( uint16_t n)
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<3;j++){};
}
