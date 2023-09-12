#ifndef TIVA_SENSOR_H
#define TIVA_SENSOR_H

#include "MCAL/Tiva_DIO/Tiva_DIO.h"
#include "MCAL/Tiva_ADC/ADC.h"


/**
 * @brief Initializes the ADC for temperature sensor on the specified base and channel.
 *
 * @param Base    The ADC base to initialize. (ADC_Base)
 * @param Channel The ADC channel to use for temperature sensing. (uint8_t)
 */
void ADC_Init_Temperature(ADC_Base Base, uint8_t Channel);

/**
 * @brief Reads the temperature value from the specified channel.
 *
 * @param Channel The ADC channel to read from. (uint8_t)
 *
 * @return The temperature value read from the ADC. (uint16_t)
 */
uint16_t Temperature_Read(uint8_t Channel);

/**
 * @brief Initializes the left LDR sensor.
 */
void LDR_Left_Init(void);

/**
 * @brief Initializes the right LDR sensor.
 */
void LDR_Right_Init(void);

/**
 * @brief Reads the value from the left LDR sensor.
 *
 * @return The value read from the left LDR sensor. (uint16_t)
 */
uint16_t LDR_Left_Read(void);

/**
 * @brief Reads the value from the right LDR sensor.
 *
 * @return The value read from the right LDR sensor. (uint16_t)
 */
uint16_t LDR_Right_Read(void);

#endif /* TIVA_SENSOR_H */
