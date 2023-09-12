


#include "Task_2.h"

/**
 * @brief Initializes the necessary components for the task.
 *        This function should be called at the beginning of the program.
 */
void Task_Initializes(void)
{
    LCD_Init();
    ADC_Init_Temperature(ADC_Base_0, CH_0);
    LDR_Right_Init();
    LDR_Left_Init();
}

/**
 * @brief Task 2 function that performs temperature and LDR readings,
 *        displays the values on an LCD, and introduces a delay.
 */
void Task_2(void)
{
    uint32_t temperature_Read = 0;
    uint32_t ldr_left_Read = 0;
    uint32_t ldr_right_Read = 0;

    // Read temperature, left LDR, and right LDR values
    temperature_Read = Temperature_Read(CH_0);
    ldr_left_Read = LDR_Left_Read();
    ldr_right_Read = LDR_Right_Read();

    // Display temperature, LDR difference on LCD
    LCD_Display(temperature_Read, ldr_left_Read, ldr_right_Read);

    // Introduce a delay of 30ms
    _delay_ms(30);
}

/**
 * @brief Displays the temperature and LDR values on an LCD.
 *
 * @param temperature_Read The temperature value to be displayed.
 * @param ldr_left_Read The value from the left LDR sensor to be displayed.
 * @param ldr_right_Read The value from the right LDR sensor to be displayed.
 */
void LCD_Display(uint32_t temperature_Read, uint32_t ldr_left_Read, uint32_t ldr_right_Read)
{
    uint32_t ldr_difference = 0;

    // Set cursor to the first line
    LCD_SetCursor(0, 0);
    LCD_WriteString("T= ");
    // Display temperature value
    LCD_WriteNumber_2D(temperature_Read);

    // Calculate LDR difference
    ldr_difference = ldr_left_Read - ldr_right_Read;

    // Set cursor to the second line
    LCD_SetCursor(1, 0);
    LCD_WriteString("LDR_Dif= ");
    // Display LDR difference value
    LCD_WriteNumber_4D(ldr_difference);
}
