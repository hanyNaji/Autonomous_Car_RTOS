/*
 * Tiva_GPTM_Timers.h
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 *
 */

#ifndef TIVA_GPTM_TIVA_GPTM_TIMERS_H_
#define TIVA_GPTM_TIVA_GPTM_TIMERS_H_



#include <stdint.h>
#include "MCAL/Tiva_DIO/Tiva_DIO.h"


/* Enumeration of available General-Purpose Timers */
typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    TIMER_W0,
    TIMER_W1,
    TIMER_W2,
    TIMER_W3,
    TIMER_W4,
    TIMER_W5
}GPTM_Type;  /*TM4C123 Timers*/


typedef enum{
    M_RESERVED=0x0,
    ONE_SHOT=0x1,
    PERIODIC=0x2,
    CAPTURE=0x3,
}GPTM_ModeType;  /*GPTM Timer Mode*/


typedef enum{
    UNCONCAT,
    CONCAT
}GPTM_ConcatType;   /*GPTMCFG values 16/32 -- 32/64*/


typedef enum{
    EDGE_COUNT,
    EDGE_TIME
}GPTM_CMType;   /*GPTM Timer Capture Mode*/


typedef enum{
    CC_MODE,
    PWM_MODE
}GPTM_alterModeSelType; /*GPTM Timer Alternate Mode Select*/

typedef enum{
    COUNT_DWON,
    COUNT_UP
}GPTM_CountDirType;  /*GPTM Timer Count Direction*/


typedef enum{
    DISABLE_INT,
    ENABLE_INT
}GPTM_MatchIntType;  /*GPTM Timer Match Interrupt Enable*/

typedef enum{
    BEGIN_ON_EN,
    WAIT_TAEN_BIT
}GPTM_WaitOnTrigerType;  /*GPTM Timer Wait-on-Trigger*/


typedef enum{
    DIS_SnapSh,
    EN_SnapSh
}GPTM_SnapShotType;  /*GPTM Timer Snap-Shot Mode*/


typedef enum{
    DIS_PWMInt,
    EN_PWMInt
}GPTM_PWMIntType;   /*GPTM Timer PWM Interrupt Enable*/


typedef enum{
    NEXT_CYCLE,
    NEXT_TIMEOUT
}GPTM_MatchRegUpdateType;   /*GPTM Timer Match Register Update*/


typedef enum{
    CCP_LOW,
    CCP_HIGH
}GPTM_PWMLegacyOpType;   /*GPTM Timer PWM Legacy Operation*/


typedef enum{
    POSITIVE= 0x00,
    NEGATIVE= 0x01,
    EM_RESERVED= 0x02,
    BOTH= 0x03
}GPTM_EventModeType;   /*GPTM Timer Event Mode*/

/*Structure to configure GPTM timer settings*/
typedef struct{
    GPTM_Type timer;
    uint8_t preScale;
    GPTM_ModeType mode;
    GPTM_ConcatType concat;
    GPTM_CMType captureMode;
    GPTM_alterModeSelType alterModeSelect;
    GPTM_CountDirType dirMode;
    GPTM_EventModeType eventMode;
    GPTM_MatchIntType intType;
    GPTM_WaitOnTrigerType startMode;
    GPTM_SnapShotType snapShot;
    GPTM_PWMIntType PWMInt;
    GPTM_MatchRegUpdateType regUpdate;
    GPTM_PWMLegacyOpType PWMLegOp;
}GPTM_Struct;




/**************** Function Prototypes *****************/

/**
 * @brief Enables the specified General-Purpose Timer Module (GPTM).
 *
 * @param timer_N The GPTM module to enable.
 */
void GPTM_Enable(GPTM_Type timer_N);

/**
 * @brief Disables the specified General-Purpose Timer Module (GPTM).
 *
 * @param timer_N The GPTM module to disable.
 */
void GPTM_Disable(GPTM_Type timer_N);

/**
 * @brief Initializes the General-Purpose Timer Module (GPTM) using the provided configuration.
 *
 * @param st_timer Pointer to a GPTM_Struct containing the timer configuration.
 */
void GPTM_Init(GPTM_Struct *st_timer);


/**
 * @brief Loads the specified value into the TimerA Interval Load Register (TAILR) for the given timer module.
 *
 * @param timer_N The GPTM module.
 * @param value The value to load into TAILR.
 */
void GPTM_TAILR_Value_Loud(GPTM_Type timer_N, uint32_t value);

/**
 * @brief Reads the captured value from the General-Purpose Timer Module (GPTM) for capture mode.
 *
 * @param timer_N The GPTM module.
 * @return The captured value.
 */
uint32_t GPTM_capture_read(GPTM_Type timer_N);

/**
 * @brief Initializes a GPIO pin for use with TimerA Capture/Compare (CCP) mode.
 *
 * @param pin The GPIO pin to initialize.
 */
void GPTM_CCP_PinInit(DIO_AllPINS_TYPE pin);

/**
 * @brief Captures the pulse width of a signal using TimerA Capture/Compare (CCP) mode.
 *
 * @param timer_N The GPTM module.
 * @param ccp_pin The GPIO pin configured for CCP mode.
 * @return The pulse width in timer ticks.
 */
uint32_t TimerA_Capture_PulseWidth(GPTM_Type timer_N, DIO_AllPINS_TYPE ccp_pin);

/**
 * @brief Initializes the PWM mode for the specified General-Purpose Timer Module (GPTM) and associated GPIO pin.
 *
 * @param timer_N The GPTM module.
 * @param pin The GPIO pin to configure for PWM mode.
 */
void GPTM_PWM_init(GPTM_Type timer_N, DIO_AllPINS_TYPE pin);

/**
 * @brief Initializes a GPIO pin for use with PWM mode.
 *
 * @param pin The GPIO pin to initialize.
 */
void GPTM_PWM_PinInit(DIO_AllPINS_TYPE pin);

/**
 * @brief Sets the duty cycle of PWM output for the specified GPTM module.
 *
 * @param timer_N The GPTM module.
 * @param pwm The PWM duty cycle value.
 */
void GPTM_PWM_Duty_Cycle(GPTM_Type timer_N, uint32_t pwm);




#endif /* TIVA_GPTM_TIVA_GPTM_TIMERS_H_ */
