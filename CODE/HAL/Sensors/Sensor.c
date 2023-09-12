

#include "Sensor.h"

/**
 * @brief Initializes the ADC module for the temperature sensor on the specified channel.
 *
 * @param ADC_Type The ADC type to initialize.
 * @param Channel  The ADC channel to use for temperature sensing.
 */

void ADC_Init_Temperature(uint8_t ADC_Type, uint8_t Channel)
{
    /* Enable the clock for the specified ADC module (ADC_Type) */
    SYSCTL_RCGCADC_R |= (1U << ADC_Type);

    /* Enable the clock for GPIO Port E */
    SYSCTL_RCGCGPIO_R |= (1U << 4);

    /* Configure GPIO pins in Port E (PE3) for alternative function (ADC) */
    GPIO_PORTE_AFSEL_R |= 0x08;

    /* Disable the digital functionality of GPIO pins in Port E (PE3) */
    GPIO_PORTE_DEN_R &= ~(0x08);

    /* Enable the analog functionality of GPIO pins in Port E (PE3) */
    GPIO_PORTE_AMSEL_R |= 0x08;

    /* Disable Sample Sequencer 3 before making changes */
    ADC0_ACTSS_R &= ~(1U << 3);

    /* Select start conversion trigger method (using software trigger) */
    ADC0_EMUX_R = 0U;

    /* Configure Sample Sequence Control for single-ended, one-conversion, and raw interrupt */
    ADC0_SSCTL3_R = (1U << 1) | (1U << 2) | (1U << 3);

    /* Enable Sample Sequencer 3 */
    ADC0_ACTSS_R |= (1U << 3);
}
/**
 * @brief Reads the temperature value from the specified channel.
 *
 * @param Channel The ADC channel to read from.
 *
 * @return The temperature value read from the ADC.
 */

uint16_t Temperature_Read(uint8_t Channel)
{
    /* Select ADC input channel */
    ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0) | Channel;

    /* Initiate the ADC conversion for Sample Sequencer 3 */
    ADC0_PSSI_R |= (1U << 3);

    /* Wait for conversion to complete */
    while ((ADC0_RIS_R & (1U << 3)) == 0) {}

    /* Read conversion result */
    uint16_t result = ADC0_SSFIFO3_R;

    /* Clear completion flag */
    ADC0_ISC_R = (1U << 3);

    /* Conversion formula to calculate temperature */
    result = (1475 - ((750 * 33 * (float)result) / 4096));

    return result;
}

/**
 * @brief Initializes the right LDR sensor.
 */


void LDR_Right_Init(void)
{
    /* Initialize the right LDR sensor using ADC_Init function*/
    ADC_Init( ADC_Base_0, ADC_Module_0, CH_1, ADC_sequencer_1);
}


/**
 * @brief Initializes the left LDR sensor.
 */

void LDR_Left_Init(void)
{
    /* Initialize the left LDR sensor using ADC_Init function*/
    ADC_Init(ADC_Base_0, ADC_Module_0, CH_2, ADC_sequencer_2);
}

/**
 * @brief Reads the value from the right LDR sensor.
 *
 * @return The value read from the right LDR sensor.
 */

uint16_t LDR_Right_Read(void)
{
    /* Use ADC_Read function to read the value from the right LDR sensor */
    return ADC_Read(ADC_Base_0, CH_1, ADC_sequencer_1);
}

/**
 * @brief Reads the value from the left LDR sensor.
 *
 * @return The value read from the left LDR sensor.
 */

uint16_t LDR_Left_Read(void)
{
    /* Use ADC_Read function to read the value from the left LDR sensor*/
    return ADC_Read(ADC_Base_0, CH_2, ADC_sequencer_2);
}



