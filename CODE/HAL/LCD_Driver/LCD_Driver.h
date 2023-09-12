/*
 * LCD_Driver.h
 *
 *  Created on: Aug 18, 2023
 *      Author: hany nagy
 */

#ifndef LCD_DRIVER_LCD_DRIVER_H_
#define LCD_DRIVER_LCD_DRIVER_H_

#include "MCAL/Tiva_DIO/Tiva_DIO.h"


/* for 8 bit mode 8 *******/
/* for 4 bit mode 4 *******/
#define   LCD_MODE    4



//#define   D0     (PE5)
//#define   D1     (PB7)
//#define   D2     (PB6)
//#define   D3     (PB5)

#define   D4     (PB4)
#define   D5     (PA5)
#define   D6     (PA6)
#define   D7     (PA7)


#define   RS     (PA2)
#define   RW     (PA3)
#define   EN     (PA4)


/****************************************************/
/**
 * @brief Initializes the LCD.
 */
void LCD_Init(void);

/**
 * @brief Clears the LCD display.
 */
void LCD_Clear(void);

/**
 * @brief Writes a character to the LCD.
 *
 * @param ch The character to be written.
 */
void LCD_WriteChar(uint8_t ch);

/**
 * @brief Writes a string to the LCD.
 *
 * @param str Pointer to the string to be written.
 */
void LCD_WriteString(uint8_t *str);

/**
 * @brief Writes a number to the LCD.
 *
 * @param num The number to be written.
 */
void LCD_WriteNumber(int32_t num);

/**
 * @brief Sets the cursor position on the LCD.
 *
 * @param Line Line number (0 or 1).
 * @param x Column number.
 */
void LCD_SetCursor(uint8_t Line, uint8_t x);

/**
 * @brief Writes a number in binary format to the LCD.
 *
 * @param num The number to be written in binary format.
 */
void LCD_WriteNumberInBinary(uint8_t num);

/**
 * @brief Writes a 4-digit number to the LCD.
 *
 * @param num The 4-digit number to be written.
 */
void LCD_WriteNumber_4D(uint16_t num);


/**
 * @brief Writes a 3-digit number to the LCD.
 *
 * @param num The 3-digit number to be written.
 */
void LCD_WriteNumber_3D(uint16_t num);

/**
 * @brief Writes a 2-digit number to the LCD.
 *
 * @param num The 2-digit number to be written.
 */
void LCD_WriteNumber_2D(uint16_t num);

#endif /* LCD_DRIVER_LCD_DRIVER_H_ */
