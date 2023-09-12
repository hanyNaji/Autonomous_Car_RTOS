/*
 * ADC.c
 *
 *  Created on: 9 Sep 2023
 *      Author: Amr Al-Kayal
 */




#include "ADC.h"

/* ADC_sequencer_EN Function */
/**
 * @brief Enables the ADC sequencer for a specific channel in the Analog-to-Digital Converter (ADC) module.
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

void ADC_sequencer_EN(ADC_Base BASE, ADC_sequencer sequencer, ADC_CH_TYPE ch)
{
    switch (BASE)
    {
        case ADC_Base_0:
            switch (sequencer)
            {
                case ADC_sequencer_0:
                    INSERT_BIT(ADC0_ACTSS_R, 0, 0);             /* Disable ADC sequencer 0 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    INSERT_BIT(ADC0_SSCTL0_R, 1, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    INSERT_BIT(ADC0_SSCTL0_R, 2, 1);
                    INSERT_BIT(ADC0_ACTSS_R, 0, 1);             /* Enable ADC sequencer 0 */
                    break;
                case ADC_sequencer_1:
                    INSERT_BIT(ADC0_ACTSS_R, 1, 0);             /* Disable ADC sequencer 1 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    INSERT_BIT(ADC0_SSCTL1_R, 1, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    INSERT_BIT(ADC0_SSCTL1_R, 2, 1);
                    INSERT_BIT(ADC0_ACTSS_R, 1, 1);             /* Enable ADC sequencer 1 */
                    break;
                case ADC_sequencer_2:
                    INSERT_BIT(ADC0_ACTSS_R, 2, 0);             /* Disable ADC sequencer 2 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    INSERT_BIT(ADC0_SSCTL2_R, 1, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    INSERT_BIT(ADC0_SSCTL2_R, 2, 1);
                    INSERT_BIT(ADC0_ACTSS_R, 2, 1);             /* Enable ADC sequencer 2 */
                    break;
                case ADC_sequencer_3:
                    INSERT_BIT(ADC0_ACTSS_R, 3, 0);             /* Disable ADC sequencer 3 */
                    ADC0_EMUX_R = 0U;                           /* Select start conversion trigger method (using software trigger) */
                    INSERT_BIT(ADC0_SSCTL3_R, 1, 1);            /* Configure Sample Sequence Control for single-ended, one-conversion */
                    INSERT_BIT(ADC0_SSCTL3_R, 2, 1);
                    INSERT_BIT(ADC0_ACTSS_R, 3, 1);             /* Enable ADC sequencer 3 */
                    break;
                default:
                    /* Handle invalid sequencer */
                    break;
            }
            break;
        case ADC_Base_1:
            /* Handle ADC Base 1 if applicable */
            break;
        default:
            /* Handle invalid ADC Base */
            break;
    }
}

/* ADC_Read Function */
/**
 * @brief Reads the converted value from the Analog-to-Digital Converter (ADC) module.
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

uint16_t ADC_Read(ADC_Base BASE, ADC_CH_TYPE ch, ADC_sequencer sequencer)
{
    uint16_t value;

    switch (sequencer)
    {
        case ADC_sequencer_0:
            ADC0_SSMUX0_R = (ADC0_SSMUX0_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            INSERT_BIT(ADC0_PSSI_R, 0, 1);                          /* Initiate the ADC conversion for Sample Sequencer 0 */
            while (!READ_BIT(ADC0_RIS_R, 0x01U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO0_R;                                 /* Read the converted value */
            INSERT_BIT(ADC0_ISC_R, 0, 1);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_1:
            ADC0_SSMUX1_R = (ADC0_SSMUX1_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            INSERT_BIT(ADC0_PSSI_R, 1, 1);                          /* Initiate the ADC conversion for Sample Sequencer 1 */
            while (!READ_BIT(ADC0_RIS_R, 0x02U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO1_R;                                 /* Read the converted value */
            INSERT_BIT(ADC0_ISC_R, 1, 1);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_2:
            ADC0_SSMUX2_R = (ADC0_SSMUX2_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            INSERT_BIT(ADC0_PSSI_R, 2, 1);                          /* Initiate the ADC conversion for Sample Sequencer 2 */
            while (!READ_BIT(ADC0_RIS_R, 0x04U))                    /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO2_R;                                 /* Read the converted value */
            INSERT_BIT(ADC0_ISC_R, 2, 1);                           /* Clear the conversion completion flag */
            break;
        case ADC_sequencer_3:
            ADC0_SSMUX3_R = (ADC0_SSMUX3_R & 0xFFFFFFF0U) | ch;    /* Select ADC input channel */
            INSERT_BIT(ADC0_PSSI_R, 3, 1);                          /* Initiate the ADC conversion for Sample Sequencer 3 */
            while (READ_BIT(ADC0_RIS_R, 0x08U))                     /* Wait for conversion to complete */
            {
            }
            value = ADC0_SSFIFO3_R;                                 /* Read the converted value */
            INSERT_BIT(ADC0_ISC_R, 3, 1);                           /* Clear the conversion completion flag */
            break;
        default:
            /* Handle invalid sequencer */
            break;
    }

    return value;
}


/* ADC_Init Function */
/**
 * @brief Initializes the Analog-to-Digital Converter (ADC) module.
 *
 * @param BASE      The ADC base address to select the ADC module. (ADC_Base)
 * @param module    The ADC module to enable. (ADC_Module)
 * @param ch        The ADC channel to configure. (ADC_CH_TYPE)
 * @param sequencer The ADC sequencer to enable for the specified channel. (ADC_sequencer)
 *
 * @return None.
 *
 * @note This function initializes the ADC module for a specific channel and sequencer.
 *       It enables the necessary GPIO pins, configures the corresponding registers,
 *       and enables the specified ADC sequencer.
 */

void ADC_Init(ADC_Base BASE, ADC_Module module, ADC_CH_TYPE ch, ADC_sequencer sequencer)
{
    switch (module)
    {
        case ADC_Module_0:
            INSERT_BIT(SYSCTL_RCGCADC_R, 0, 1);   /* Enable ADC Module 0 */
            break;
        case ADC_Module_1:
            INSERT_BIT(SYSCTL_RCGCADC_R, 1, 1);   /* Enable ADC Module 1 */
            break;
        default:
            /* Handle invalid ADC Module */
            break;
    }

    switch (ch)
    {
        case CH_0:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 3, 1); /* Enable alternate function for PE3 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 3, 0);   /* Disable digital function for PE3 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 3, 1); /* Enable analog mode for PE3 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_0 */
            break;
        case CH_1:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 2, 1); /* Enable alternate function for PE2 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 2, 0);   /* Disable digital function for PE2 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 2, 1); /* Enable analog mode for PE2 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_1 */
            break;
        case CH_2:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 1, 1); /* Enable alternate function for PE1 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 1, 0);   /* Disable digital function for PE1 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 1, 1); /* Enable analog mode for PE1 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_2 */
            break;
        case CH_3:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 0, 1); /* Enable alternate function for PE0 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 0, 0);   /* Disable digital function for PE0 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 0, 1); /* Enable analog mode for PE0 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_3 */
            break;
        case CH_4:
            DIO_PORT_Init(PORTD);                 /* Initialize Port D */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 3, 1); /* Enable alternate function for PD3 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 3, 0);   /* Disable digital function for PD3 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 3, 1); /* Enable analog mode for PD3 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_4 */
            break;
        case CH_5:
            DIO_PORT_Init(PORTD);                 /* Initialize Port D */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 2, 1); /* Enable alternate function for PD2 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 2, 0);   /* Disable digital function for PD2 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 2, 1); /* Enable analog mode for PD2 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_5 */
            break;
        case CH_6:
            DIO_PORT_Init(PORTD);                 /* Initialize Port D */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 1, 1); /* Enable alternate function for PD1 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 1, 0);   /* Disable digital function for PD1 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 1, 1); /* Enable analog mode for PD1 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_6 */
            break;
        case CH_7:
            DIO_PORT_Init(PORTD);                 /* Initialize Port D */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 0, 1); /* Enable alternate function forPD0 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 0, 0);   /* Disable digital function for PD0 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 0, 1); /* Enable analog mode for PD0 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_7 */
            break;
        case CH_8:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 5, 1); /* Enable alternate function for PE5 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 5, 0);   /* Disable digital function for PE5 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 5, 1); /* Enable analog mode for PE5 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_8 */
            break;
        case CH_9:
            DIO_PORT_Init(PORTE);                 /* Initialize Port E */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 4, 1); /* Enable alternate function for PE4 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 4, 0);   /* Disable digital function for PE4 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 4, 1); /* Enable analog mode for PE4 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_9 */
            break;
        case CH_10:
            DIO_PORT_Init(PORTB);                 /* Initialize Port B */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 4, 1); /* Enable alternate function for PB4 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 4, 0);   /* Disable digital function for PB4 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 4, 1); /* Enable analog mode for PB4 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_10 */
            break;
        case CH_11:
            DIO_PORT_Init(PORTB);                 /* Initialize Port B */
            INSERT_BIT(GPIO_PORTE_AFSEL_R, 5, 1); /* Enable alternate function for PB5 */
            INSERT_BIT(GPIO_PORTE_DEN_R, 5, 0);   /* Disable digital function for PB5 */
            INSERT_BIT(GPIO_PORTE_AMSEL_R, 5, 1); /* Enable analog mode for PB5 */
            ADC_sequencer_EN(BASE, sequencer, ch); /* Enable ADC sequencer for CH_11 */
            break;
        default:
            /* Handle invalid Channel */
            break;
    }
}




