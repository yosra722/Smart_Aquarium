/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM2 PRIVATE FILE                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef TIM2_PRIVATE_H_
#define TIM2_PRIVATE_H_

/* Timer 2 Hardware Registers */
#define TCCR2    *((volatile u8*)0x45)
#define TCNT2    *((volatile u8*)0x44)
#define OCR2     *((volatile u8*)0x43)
#define TIMSK    *((volatile u8*)0x59)
#define TIFR     *((volatile u8*)0x58)

/* TCCR2 Register Bits */
#define CS20     0
#define CS21     1
#define CS22     2
#define WGM21    3
#define COM20    4
#define COM21    5
#define WGM20    6
#define FOC2     7

/* TIMSK  Bits */
#define TOIE2    6
#define OCIE2    7

/* TIFR  Bits */
#define TOV2     6
#define OCF2     7

/* Timer2 Modes  */
#define TIM2_NORMAL_MODE    0
#define TIM2_CTC_MODE       2
#define TIM2_FAST_PWM_MODE  3


/* Prescaler Options */
#define TIM2_NO_CLOCK          0
#define TIM2_PRESCALER_1       1
#define TIM2_PRESCALER_8       2
#define TIM2_PRESCALER_64      3
#define TIM2_PRESCALER_256     4
#define TIM2_PRESCALER_1024    5
#define TIM2_EXT_CLOCK_FALLING 6
#define TIM2_EXT_CLOCK_RISING  7

/* Fast PWM OC2 PINS MODES*/
#define TIM2_PWM_DISCONNECTED     0
#define TIM2_PWM_NON_INVERTING    2
#define TIM2_PWM_INVERTING        3



#endif /* TIM2_PRIVATE_H_ */
