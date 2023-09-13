/*
 * systick.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */


#include "systick.h"


/********************** SYSTICK ***********************/

/**
 * @brief Initializes the SysTick timer with the specified interrupt enable status (ST_INTDISABLE or ST_INTENABLE).
 */
void SysTick_Init(ST_CTRL_INTEN_Type INTEN)
{

    INSERT_BIT(NVIC_ST_CTRL_R, 2, 1);       /* clock source: 0: Precision internal oscillator (PIOSC) divided by 4 / 1: System clock */
    INSERT_BIT(NVIC_ST_CTRL_R, 1, INTEN);   /* Interrupt Enable */
}

/**
 * @brief Disables the SysTick timer.
 */
void SysTick_Disable(void)
{
    INSERT_BIT(NVIC_ST_CTRL_R, 0, 0);
}

/**
 * @brief Enables the SysTick timer.
 */
void SysTick_Enable(void)
{
    INSERT_BIT(NVIC_ST_CTRL_R, 0, 1);       /* SysTick Enable */
}

/**
 * @brief Reads the current value of the SysTick counter.
 *
 * @return The current value of the SysTick counter.
 */
uint8_t SysTick_Read_COUNT(void)
{
    uint8_t read = READ_BIT(NVIC_ST_CTRL_R, 16);
    return read;
}

/**
 * @brief Reads the current value of the SysTick counter.
 *
 * @return The current value of the SysTick counter in milliseconds.
 */
uint32_t SysTick_Read_ms(void)
{
    return  NVIC_ST_CURRENT_R;
}

/**
 * @brief Reloads the SysTick timer with a specified value in milliseconds.
 */
void SysTick_Reload_ms(uint32_t value_ms)
{
    unsigned long long value=0;
    value = (value_ms * 16000) + (value_ms * 24) -1;
    /* check for overflow */
    if(value > 16777215){
        value = 16777215;
    }
    else
    {
        NVIC_ST_RELOAD_R = value;
        NVIC_ST_CURRENT_R =value;
    }
}

