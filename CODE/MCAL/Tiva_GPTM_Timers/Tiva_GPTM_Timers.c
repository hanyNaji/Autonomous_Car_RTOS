/*
 * Tiva_GPTM_Timers.c
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 */


#include "Tiva_GPTM_Timers.h"



/**
 * @brief Reads the captured value from the General-Purpose Timer Module (GPTM) for capture mode.
 *
 * @param timer_N The GPTM module.
 * @return The captured value.
 */
uint32_t GPTM_capture_read(GPTM_Type timer_N)
{
    uint32_t read = 0UL;
    switch(timer_N){
            case TIMER0:
                read = (uint32_t)TIMER0_TAR_R;
                break;
            case TIMER1:
                read = (uint32_t)TIMER1_TAR_R;
                break;
            case TIMER2:
                read = (uint32_t)TIMER2_TAR_R;
                break;
            case TIMER3:
                read = (uint32_t)TIMER3_TAR_R;
                break;
            case TIMER4:
                read = (uint32_t)TIMER4_TAR_R;
                break;
            case TIMER5:
                read = (uint32_t)TIMER5_TAR_R;
                break;
            case TIMER_W0:
                read = (uint32_t)WTIMER0_TAR_R;
                break;
            case TIMER_W1:
                read = (uint32_t)WTIMER1_TAR_R;
                break;
            case TIMER_W2:
                read = (uint32_t)WTIMER2_TAR_R;
                break;
            case TIMER_W3:
                read = (uint32_t)WTIMER3_TAR_R;
                break;
            case TIMER_W4:
                read = (uint32_t)WTIMER4_TAR_R;
                break;
            case TIMER_W5:
                read = (uint32_t)WTIMER5_TAR_R;
                break;
            default:
                break;
        }
    return read;
}

/**
 * @brief Enables the specified General-Purpose Timer Module (GPTM).
 *
 * @param timer_N The GPTM module to enable.
 */
void GPTM_Enable(GPTM_Type timer_N)
{
    switch(timer_N){
            case TIMER0:
                INSERT_BIT(TIMER0_CTL_R, 0UL, 1UL);
                break;
            case TIMER1:
                INSERT_BIT(TIMER1_CTL_R, 0UL, 1UL);
                break;
            case TIMER2:
                INSERT_BIT(TIMER2_CTL_R, 0UL, 1UL);
                break;
            case TIMER3:
                INSERT_BIT(TIMER3_CTL_R, 0UL, 1UL);
                break;
            case TIMER4:
                INSERT_BIT(TIMER4_CTL_R, 0UL, 1UL);
                break;
            case TIMER5:
                INSERT_BIT(TIMER5_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W0:
                INSERT_BIT(WTIMER0_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W1:
                INSERT_BIT(WTIMER1_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W2:
                INSERT_BIT(WTIMER2_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W3:
                INSERT_BIT(WTIMER3_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W4:
                INSERT_BIT(WTIMER4_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W5:
                INSERT_BIT(WTIMER5_CTL_R, 0UL, 1UL);
                break;
            default:
                break;
        }

}

/**
 * @brief Disables the specified General-Purpose Timer Module (GPTM).
 *
 * @param timer_N The GPTM module to disable.
 */
void GPTM_Disable(GPTM_Type timer_N)
{
    switch(timer_N){
        case TIMER0:
            INSERT_BIT(TIMER0_CTL_R, 0UL, 0UL);
            break;
        case TIMER1:
            INSERT_BIT(TIMER1_CTL_R, 0UL, 0UL);
            break;
        case TIMER2:
            INSERT_BIT(TIMER2_CTL_R, 0UL, 0UL);
            break;
        case TIMER3:
            INSERT_BIT(TIMER3_CTL_R, 0UL, 0UL);
            break;
        case TIMER4:
            INSERT_BIT(TIMER4_CTL_R, 0UL, 0UL);
            break;
        case TIMER5:
            INSERT_BIT(TIMER5_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W0:
            INSERT_BIT(WTIMER0_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W1:
            INSERT_BIT(WTIMER1_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W2:
            INSERT_BIT(WTIMER2_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W3:
            INSERT_BIT(WTIMER3_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W4:
            INSERT_BIT(WTIMER4_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W5:
            INSERT_BIT(WTIMER5_CTL_R, 0UL, 0UL);
            break;
        default:
            break;
    }

}


/**
 * @brief Initializes the General-Purpose Timer Module (GPTM) using the provided configuration.
 *
 * @param st_timer Pointer to a GPTM_Struct containing the timer configuration.
 */
void GPTM_Init(GPTM_Struct *st_timer)
{
    switch(st_timer->timer){
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0UL, 1UL);
            INSERT_BIT(TIMER0_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    TIMER0_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER0_IMR_R, 0UL, st_timer->intType);
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER0_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER0_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER0_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER0_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER1:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 1UL, 1UL);
            INSERT_BIT(TIMER1_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    TIMER1_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER1_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER1_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER1_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER1_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER1_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2UL, 1UL);
            INSERT_BIT(TIMER2_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    TIMER2_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER2_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER2_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER2_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER2_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER2_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER3:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 3UL, 1UL);
            INSERT_BIT(TIMER3_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    TIMER3_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER3_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER3_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER3_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER3_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER3_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER4:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 4UL, 1UL);
            INSERT_BIT(TIMER4_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    TIMER4_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER4_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER4_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER4_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER4_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER4_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER5:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 5UL, 1UL);
            INSERT_BIT(TIMER5_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    TIMER5_CFG_R = 0x00000000;
                    INSERT_BITS(TIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(TIMER5_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER5_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER5_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER5_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER5_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0UL, 1UL);
            INSERT_BIT(WTIMER0_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER0_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER0_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER0_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER0_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER0_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    INSERT_BIT(WTIMER0_IMR_R, 2UL, st_timer->intType);
                    break;
                default:
                    break;
            }
            WTIMER0_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W1:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 1UL, 1UL);
            INSERT_BIT(WTIMER1_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER1_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER1_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER1_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER1_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER1_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER1_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2UL, 1UL);
            INSERT_BIT(WTIMER2_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER2_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER2_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER2_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER2_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER2_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER2_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W3:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 3UL, 1UL);
            INSERT_BIT(WTIMER3_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER3_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER3_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER3_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER3_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER3_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER3_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W4:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 4UL, 1UL);
            INSERT_BIT(WTIMER4_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER4_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER4_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER4_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER4_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER4_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER4_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W5:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 5UL, 1UL);
            INSERT_BIT(WTIMER5_CTL_R, 0UL, 0UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                case PERIODIC:
                    WTIMER5_CFG_R = 0x00000000;
                    INSERT_BITS(WTIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BIT(WTIMER5_IMR_R, 0UL, st_timer->intType);
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER5_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER5_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER5_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER5_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        default:
            break;
    }
}


/**
 * @brief Loads the specified value into the TimerA Interval Load Register (TAILR) for the given timer module.
 *
 * @param timer_N The GPTM module.
 * @param value The value to load into TAILR.
 */
void GPTM_TAILR_Value_Loud(GPTM_Type timer_N, uint32_t value)
{

    switch(timer_N){
            case TIMER0:
                TIMER0_TAILR_R = value -1;    /* 60*(16000000U-1) for one minute */
                break;
            case TIMER1:
                TIMER1_TAILR_R = value -1;
                break;
            case TIMER2:
                TIMER2_TAILR_R = value -1;
                break;
            case TIMER3:
                TIMER3_TAILR_R = value -1;
                break;
            case TIMER4:
                TIMER4_TAILR_R = value -1;
                break;
            case TIMER5:
                TIMER5_TAILR_R = value -1;
                break;
            case TIMER_W0:
                WTIMER0_TAILR_R = value -1;
                break;
            case TIMER_W1:
                WTIMER1_TAILR_R = value -1;
                break;
            case TIMER_W2:
                WTIMER2_TAILR_R = value -1;
                break;
            case TIMER_W3:
                WTIMER3_TAILR_R = value -1;
                break;
            case TIMER_W4:
                WTIMER4_TAILR_R = value -1;
                break;
            case TIMER_W5:
                WTIMER5_TAILR_R = value -1;
                break;
            default:
                break;
        }
}

/**
 * @brief Initializes a GPIO pin for use with TimerA Capture/Compare (CCP) mode.
 *
 * @param pin The GPIO pin to initialize.
 */
void GPTM_CCP_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port_N = (uint8_t) pin / 8;
    switch (Port_N)
    {
        case PORTA:
            INSERT_BITS(GPIO_PORTA_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTB:
            INSERT_BITS(GPIO_PORTB_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTC:
            INSERT_BITS(GPIO_PORTC_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTD:
            INSERT_BITS(GPIO_PORTD_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTE:
            INSERT_BITS(GPIO_PORTE_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTF:
            INSERT_BITS(GPIO_PORTF_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        default:
            break;
    }
}




/**
 * @brief Captures the pulse width of a signal using TimerA Capture/Compare (CCP) mode.
 *
 * @param timer_N The GPTM module.
 * @param ccp_pin The GPIO pin configured for CCP mode.
 * @return The pulse width in timer ticks.
 */
uint32_t TimerA_Capture_PulseWidth(GPTM_Type timer_N, DIO_AllPINS_TYPE ccp_pin)
{
    uint32_t risingEdge=0, fallingEdge=0;
    switch (timer_N)
    {
        case TIMER0:
            while(1)
            {
                INSERT_BIT(TIMER0_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER0_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER0_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER0_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER0_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER0_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER1:
            while(1)
            {
                INSERT_BIT(TIMER1_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER1_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER1_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER1_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER1_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER1_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER2:
            while(1)
            {
                INSERT_BIT(TIMER2_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER2_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER2_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER2_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER2_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER2_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER3:
            while(1)
            {
                INSERT_BIT(TIMER3_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER3_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER3_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER3_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER3_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER3_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER4:
            while(1)
            {
                INSERT_BIT(TIMER4_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER4_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER4_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER4_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER4_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER4_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER5:
            while(1)
            {
                INSERT_BIT(TIMER5_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER5_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER5_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER5_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER5_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER5_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W0:
            while(1)
            {
                INSERT_BIT(WTIMER0_ICR_R, 2UL, 1UL);                /* clear WTIMER0A capture flag */
                while(! DIO_ReadPin(ccp_pin));               /* wait till captured */
                risingEdge = WTIMER0_TAR_R;     /* save the timestamp */
                /* detect falling edge */
                INSERT_BIT(WTIMER0_ICR_R, 2UL, 1UL);                /* clear WTIMER0A capture flag */
                while(DIO_ReadPin(ccp_pin));                 /* wait till captured */
                fallingEdge = WTIMER0_TAR_R;    /* save the timestamp */
                return (fallingEdge - risingEdge);     /* return the time difference */
            }
            break;
        case TIMER_W1:
            while(1)
            {
                INSERT_BIT(WTIMER1_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER1_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER1_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER1_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER1_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER1_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W2:
            while(1)
            {
                INSERT_BIT(WTIMER2_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER2_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER2_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER2_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER2_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER2_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W3:
            while(1)
            {
                INSERT_BIT(WTIMER3_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER3_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER3_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER3_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER3_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER3_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W4:
            while(1)
            {
                INSERT_BIT(WTIMER4_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER4_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER4_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER4_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER4_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER4_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W5:
            while(1)
            {
                INSERT_BIT(WTIMER5_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER5_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER5_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER5_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER5_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER5_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        default:
            break;
    }
    return 0;
}


/**
 * @brief Initializes the PWM mode for the specified General-Purpose Timer Module (GPTM) and associated GPIO pin.
 *
 * @param timer_N The GPTM module.
 * @param pin The GPIO pin to configure for PWM mode.
 */
void GPTM_PWM_init(GPTM_Type timer_N, DIO_AllPINS_TYPE pin)
{
    switch(timer_N)
    {
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0UL, 1UL);
            INSERT_BIT(TIMER0_CTL_R, 0, 0);
            TIMER0_CFG_R=0x4; /*Enable PWM*/

            TIMER0_TAMR_R|=0x2;
            INSERT_BIT(TIMER0_TAMR_R, 3, 1);
            INSERT_BIT(TIMER0_TAMR_R, 2, 0);

            INSERT_BIT(TIMER0_CTL_R, 6, 0);
            TIMER0_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER0_CTL_R, 0, 1);
            break;
        case TIMER1:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 1UL, 1UL);
            INSERT_BIT(TIMER1_CTL_R, 0, 0);
            TIMER1_CFG_R=0x4; /*Enable PWM*/

            TIMER1_TAMR_R|=0x2;
            INSERT_BIT(TIMER1_TAMR_R, 3, 1);
            INSERT_BIT(TIMER1_TAMR_R, 2, 0);

            INSERT_BIT(TIMER1_CTL_R, 6, 0);
            TIMER1_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER1_CTL_R, 0, 1);
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2UL, 1UL);
            INSERT_BIT(TIMER2_CTL_R, 0, 0);
            TIMER2_CFG_R=0x4; /*Enable PWM*/

            TIMER2_TAMR_R|=0x2;
            INSERT_BIT(TIMER2_TAMR_R, 3, 1);
            INSERT_BIT(TIMER2_TAMR_R, 2, 0);

            INSERT_BIT(TIMER2_CTL_R, 6, 0);
            TIMER2_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER2_CTL_R, 0, 1);
            break;
        case TIMER3:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 3UL, 1UL);
            INSERT_BIT(TIMER3_CTL_R, 0, 0);
            TIMER3_CFG_R=0x4; /*Enable PWM*/

            TIMER3_TAMR_R|=0x2;
            INSERT_BIT(TIMER3_TAMR_R, 3, 1);
            INSERT_BIT(TIMER3_TAMR_R, 2, 0);

            INSERT_BIT(TIMER3_CTL_R, 6, 0);
            TIMER3_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER3_CTL_R, 0, 1);
            break;
        case TIMER4:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 4UL, 1UL);
            INSERT_BIT(TIMER4_CTL_R, 0, 0);
            TIMER4_CFG_R=0x4; /*Enable PWM*/

            TIMER4_TAMR_R|=0x2;
            INSERT_BIT(TIMER4_TAMR_R, 3, 1);
            INSERT_BIT(TIMER4_TAMR_R, 2, 0);

            INSERT_BIT(TIMER4_CTL_R, 6, 0);
            TIMER4_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER4_CTL_R, 0, 1);
            break;
        case TIMER5:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 5UL, 1UL);
            INSERT_BIT(TIMER5_CTL_R, 0, 0);
            TIMER5_CFG_R=0x4; /*Enable PWM*/

            TIMER5_TAMR_R|=0x2;
            INSERT_BIT(TIMER5_TAMR_R, 3, 1);
            INSERT_BIT(TIMER5_TAMR_R, 2, 0);

            INSERT_BIT(TIMER5_CTL_R, 6, 0);
            TIMER5_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER5_CTL_R, 0, 1);
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0UL, 1UL);
            INSERT_BIT(WTIMER0_CTL_R, 0, 0);
            WTIMER0_CFG_R=0x4; /*Enable PWM*/

            WTIMER0_TAMR_R|=0x2;
            INSERT_BIT(WTIMER0_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER0_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER0_CTL_R, 6, 0);
            WTIMER0_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER0_CTL_R, 0, 1);
            break;
        case TIMER_W1:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 1UL, 1UL);
            INSERT_BIT(WTIMER1_CTL_R, 0, 0);
            WTIMER1_CFG_R=0x4; /*Enable PWM*/

            WTIMER1_TAMR_R|=0x2;
            INSERT_BIT(WTIMER1_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER1_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER1_CTL_R, 6, 0);
            WTIMER1_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER1_CTL_R, 0, 1);
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2UL, 1UL);
            INSERT_BIT(WTIMER2_CTL_R, 0, 0);
            WTIMER2_CFG_R=0x4; /*Enable PWM*/

            WTIMER2_TAMR_R|=0x2;
            INSERT_BIT(WTIMER2_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER2_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER2_CTL_R, 6, 0);
            WTIMER2_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER2_CTL_R, 0, 1);
            break;
        case TIMER_W3:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 3UL, 1UL);
            INSERT_BIT(WTIMER3_CTL_R, 0, 0);
            WTIMER3_CFG_R=0x4; /*Enable PWM*/

            WTIMER3_TAMR_R|=0x2;
            INSERT_BIT(WTIMER3_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER3_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER3_CTL_R, 6, 0);
            WTIMER3_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER3_CTL_R, 0, 1);
            break;
        case TIMER_W4:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 4UL, 1UL);
            INSERT_BIT(WTIMER4_CTL_R, 0, 0);
            WTIMER4_CFG_R=0x4; /*Enable PWM*/

            WTIMER4_TAMR_R|=0x2;
            INSERT_BIT(WTIMER4_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER4_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER4_CTL_R, 6, 0);
            WTIMER4_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER4_CTL_R, 0, 1);
            break;
        case TIMER_W5:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 5UL, 1UL);
            INSERT_BIT(WTIMER5_CTL_R, 0, 0);
            WTIMER5_CFG_R=0x4; /*Enable PWM*/

            WTIMER5_TAMR_R|=0x2;
            INSERT_BIT(WTIMER5_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER5_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER5_CTL_R, 6, 0);
            WTIMER5_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER5_CTL_R, 0, 1);
            break;
        default:
            break;

    }

    GPTM_PWM_PinInit(pin);
}

/**
 * @brief Initializes a GPIO pin for use with PWM mode.
 *
 * @param pin The GPIO pin to initialize.
 */
void GPTM_PWM_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port_N = pin / PB0;
    uint8_t pin_num = pin % PB0;

    switch (Port_N)
    {
        case PORTA:
            DIO_PORT_Init(PORTA);
            GPIO_PORTA_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTA_PCTL_R |= (0x07 << (pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTB:
            DIO_PORT_Init(PORTB);
            GPIO_PORTB_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTB_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTC:
            DIO_PORT_Init(PORTC);
            GPIO_PORTC_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTC_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTD:
            DIO_PORT_Init(PORTD);
            GPIO_PORTD_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTD_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTE:
            DIO_PORT_Init(PORTE);
            GPIO_PORTE_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTE_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTF:
            DIO_PORT_Init(PORTF);
            GPIO_PORTF_AFSEL_R |= (1 << pin_num);         /* Data sheet page 671 */
            GPIO_PORTF_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        default:
            break;
    }
}


/**
 * @brief Sets the duty cycle of PWM output for the specified GPTM module.
 *
 * @param timer_N The GPTM module.
 * @param pwm The PWM duty cycle value.
 */
void GPTM_PWM_Duty_Cycle (GPTM_Type timer_N, uint32_t pwm)
{
        switch(timer_N)
        {
            case TIMER0:
                TIMER0_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER1:
                TIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER2:
                TIMER2_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER3:
                TIMER3_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER4:
                TIMER4_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER5:
                TIMER5_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W0:
                WTIMER0_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W1:
                WTIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W2:
                WTIMER2_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W3:
                WTIMER3_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W4:
                WTIMER4_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W5:
                WTIMER5_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            default:
                break;
        }
}


void GPTM_PWM_Freq_KHZ(uint16_t freq)
{
    if (freq==0);
    else
    {
        uint16_t Ttotal=1000/freq;
        if (Ttotal>=1)
        {
            TIMER1_TAMATCHR_R=Ttotal-1;
        }
        else TIMER1_TAMATCHR_R=0;

    }
}


