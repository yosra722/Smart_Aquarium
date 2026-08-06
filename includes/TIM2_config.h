/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM2 CONFIG FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef TIM2_CONFIG_H_
#define TIM2_CONFIG_H_

/*
 Select Timer 2 Mode:
 - TIM2_NORMAL_MODE
 - TIM2_CTC_MODE
 - TIM2_FAST_PWM_MODE
 */
#define TIM2_MODE        TIM2_CTC_MODE

/*
  Select Timer 2 Prescaler:
 - TIM2_NO_CLOCK
 - TIM2_PRESCALER_1
 - TIM2_PRESCALER_8
 - TIM2_PRESCALER_64
 - TIM2_PRESCALER_256
 - TIM2_PRESCALER_1024
 - TIM2_EXT_CLOCK_FALLING
 - TIM2_EXT_CLOCK_RISING
 */
#define TIM2_PRESCALER    TIM2_PRESCALER_64

/*
PWM MODES:
TIM2_PWM_DISCONNECTED
TIM2_PWM_NON_INVERTING
TIM2_PWM_INVERTING
*/
#define FAST_PWM_MODE   TIM2_PWM_NON_INVERTING

#endif /* TIM2_CONFIG_H_ */
