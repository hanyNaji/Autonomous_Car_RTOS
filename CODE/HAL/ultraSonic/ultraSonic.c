/*
 * ultraSonic.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */


#include "ultraSonic.h"



static DIO_AllPINS_TYPE trig_pin ;
static DIO_AllPINS_TYPE echo_pin ;

/* Configuration for the GPTM_EdgeTimer */
GPTM_Struct GPTM_EdgeTimer =
{
    TIMER_W0,           /* Timer type */
    0x00UL,             /* Pre-scale value */
    CAPTURE,            /* Timer mode */
    UNCONCAT,           /* Concatenation mode */
    EDGE_TIME,          /* Capture mode */
    CC_MODE,            /* Timer alternate mode */
    COUNT_UP,           /* Timer count direction */
    BOTH,               /* Event mode */
    ENABLE_INT,        /* Match interrupt type */
    WAIT_TAEN_BIT,      /* Start mode */
    DIS_SnapSh,         /* Snapshot mode */
    DIS_PWMInt,         /* PWM interrupt type */
    NEXT_CYCLE,         /* Match register update */
    CCP_LOW             /* PWM legacy operation */
};



/**
 * @brief Initializes the UltraSonic Sensor with the specified trigger and echo pins.
 *
 * @param trigg The trigger pin of the ultrasonic sensor (output pin).
 * @param echoo The echo pin of the ultrasonic sensor (input pin).
 */
void ultraSonic_Init(DIO_AllPINS_TYPE trigg, DIO_AllPINS_TYPE echoo)
{
    trig_pin = trigg;
    echo_pin = echoo;

    DIO_PORT_Init(trig_pin/PB0);
    DIO_PORT_Init(echo_pin/PB0);

    DIO_InitPin(trig_pin, OUTPUT);
    DIO_WritePin(trig_pin, LOW);
    DIO_InitPin(echo_pin, INFREE);

    /* Initialize GPTM CCP pin */
    GPTM_CCP_PinInit(echo_pin);

    /* Initialize and enable GPTM_EdgeTimer */
    GPTM_Init(&GPTM_EdgeTimer);
    GPTM_Enable(GPTM_EdgeTimer.timer);
}

/**
 * @brief Reads the distance measured by the ultrasonic sensor and returns the value in centimeters (cm).
 *
 * @return The measured distance in centimeters.
 */
uint32_t ultraSonic_Read_CM(void)
{
    uint32_t dist=0;
    uint32_t readtime=0;

    /* Make the pulse for triggering the sound wave */
    DIO_WritePin(trig_pin, LOW);
    _delay_us(2);
    DIO_WritePin(trig_pin, HIGH);
    _delay_us(10);
    DIO_WritePin(trig_pin, LOW);

    readtime = TimerA_Capture_PulseWidth(TIMER_W0, echo_pin);   /* Reading the wave (ON) time */
    dist = ((readtime/16/2) * 29) + 1;     /* Ultra-Sonic Equation to get correct distance sound speed = 29us/cm */

    return dist;
}
