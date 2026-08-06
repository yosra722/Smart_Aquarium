/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 03/08/2026   ************/
/************** File  : Configuration File  *****/
/********* Last Update: 03/08/2026   ************/
/************************************************/

#define TIM0_CONFIG_H
#ifdef  TIM0_CONFIG_H

#define TIM0_MODE          TIM0_OVERFLOW // TIM0_OVERFLOW , TIM0_PWM ,TIM0_CTC, TIM0_FAST_PWM
#define TIM0_PRESCALLER    TIM0_CLK_by_1
/******TIM0_PRESCALLER options****/
/*
 TIM0_NO_CLK
 TIM0_CLK_by_1
 TIM0_CLK_by_8
 TIM0_CLK_by_64
 TIM0_CLK_by_256
 TIM0_CLK_by_1024
 TIM0_EXT_CLK_ON_T0_FALLINGEDGE
 TIM0_EXT_CLK_ON_T0_RISINGEDGE
 */

#endif

/***  ASK ABOUT THAT PART  ***/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
