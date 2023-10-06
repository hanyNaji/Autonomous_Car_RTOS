

#ifndef MCAL_TIVA_ADC_ADC_H_
#define MCAL_TIVA_ADC_ADC_H_


#include <stdint.h>


/**
 * @file ADC.h
 * @brief ADC Driver Module
 *
 * This header file contains the declarations of functions and enums for the ADC driver module.
 * It provides functions to initialize the ADC module, enable the ADC sequencer, and read the converted value.
 * The module utilizes the Tiva_DIO module for GPIO pin operations.
 */

/**
 * @defgroup ADC ADC Driver Module
 * @{
 */



/**
 * @brief Enumeration for ADC base address selection.
 */

typedef enum{
    ADC_Base_0, /**< ADC Base 0 */
    ADC_Base_1  /**< ADC Base 1 */
}ADC_Base;


/**
 * @brief Enumeration for ADC sequencer selection.
 */

typedef enum{
    ADC_sequencer_0,    /**< ADC Sequencer 0 */
    ADC_sequencer_1,    /**< ADC Sequencer 1 */
    ADC_sequencer_2,    /**< ADC Sequencer 2 */
    ADC_sequencer_3     /**< ADC Sequencer 3 */
}ADC_sequencer;


/**
 * @brief Enumeration for ADC channel selection.
 */

typedef enum{
    CH_0,   /**< ADC Channel 0 */
    CH_1,   /**< ADC Channel 1 */
    CH_2,   /**< ADC Channel 2 */
    CH_3,   /**< ADC Channel 3 */
    CH_4,   /**< ADC Channel 4 */
    CH_5,   /**< ADC Channel 5 */
    CH_6,   /**< ADC Channel 6 */
    CH_7,   /**< ADC Channel 7 */
    CH_8,   /**< ADC Channel 8 */
    CH_9,   /**< ADC Channel 9 */
    CH_10,  /**< ADC Channel 10 */
    CH_11   /**< ADC Channel 11 */
}ADC_CH_TYPE;

/**
 * @brief Enumeration for ADC module selection.
 */
typedef enum{
    ADC_Module_0,  /**< ADC Module 0 */
    ADC_Module_1   /**< ADC Module 1 */
}ADC_Module;


/**
 * @brief Initializes the ADC module for a specific channel and sequencer.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param module    The ADC module to enable. (ADC_Module)
 * @param ch        The ADC channel to configure. (ADC_CH_TYPE)
 * @param sequencer The ADC sequencer to enable for the specified channel. (ADC_sequencer)
 *
 * @note This function initializes the ADC module for a specific channel and sequencer.
 *       It enables the necessary GPIO pins, configures the corresponding registers,
 *       and enables the specified ADC sequencer.
 */
void ADC_Init(ADC_Base BASE, ADC_Module module, ADC_CH_TYPE ch, ADC_sequencer sequencer);

/**
 * @brief Reads the converted value from the ADC module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param ch        The ADC channel to read the converted value from. (ADC_CH_TYPE)
 * @param sequencer The ADC sequencer to read the converted value from. (ADC_sequencer)
 *
 * @return The converted value read from the ADC.
 *
 * @note This function reads the converted value from the ADC module for a specific channel and sequencer.
 *       It waits for the conversion to complete, retrieves the converted value,
 *       and returns it to the caller.
 */
uint16_t ADC_Read(ADC_Base BASE, ADC_CH_TYPE ch, ADC_sequencer sequencer);

/**
 * @brief Enables the ADC sequencer for a specific channel in the ADC module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param sequencer The ADC sequencer to enable. (ADC_sequencer)
 * @param ch        The ADC channel to associate with the sequencer. (ADC_CH_TYPE)
 *
 * @return None.
 *
 * @note This function enables the specified ADC sequencer for the given channel.
 *       It configures the ADC module registers to associate the sequencer with the channel
 *       and enables the sequencer for subsequent conversions.
 */
void ADC_sequencer_EN(ADC_Base BASE, ADC_sequencer sequencer, ADC_CH_TYPE ch);

/** @} */


#endif /* MCAL_TIVA_ADC_ADC_H_ */
