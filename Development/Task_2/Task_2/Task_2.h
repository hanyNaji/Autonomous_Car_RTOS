#ifndef TASK_2_H_
#define TASK_2_H_

#include "HAL/LCD_Driver/LCD_Driver.h"
#include "HAL/Sensors/Sensor.h"
#include "MCAL/Tiva_DIO/Tiva_DIO.h"

/**
 * @brief Task 2 function that performs temperature and LDR readings,
 *        displays the values on an LCD, and introduces a delay.
 */
void Task_2(void);

/**
 * @brief Initializes the necessary components for the task.
 *        This function should be called at the beginning of the program.
 */
void Task_Initializes(void);

/**
 * @brief Displays the temperature and LDR values on an LCD.
 *
 * @param temperature_Read The temperature value to be displayed.
 * @param ldr_left_Read The value from the left LDR sensor to be displayed.
 * @param ldr_right_Read The value from the right LDR sensor to be displayed.
 */
void LCD_Display(uint32_t temperature_Read, uint32_t ldr_left_Read, uint32_t ldr_right_Read);

#endif /* TASK_2_H_ */
