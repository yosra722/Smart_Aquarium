/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 03/08/2026   *************/
/************** File  : Private  File  **********/
/********* Last Update: 03/08/2026   ************/
/************************************************/

#define TIM0_PRIVATE_H
#ifdef  TIM0_PRIVATE_H

#define TCCR0        *((volatile u8 *)0x53 )
#define TCNT0        *((volatile u8 *)0x52 )
#define OCR0         *((volatile u8 *)0x5C )
#define TIMSK        *((volatile u8 *)0x59 )
#define TIFR         *((volatile u8 *)0x58 )

/*
#define TIM0_OV_INTERRUPT_BIT    TIMSK,0
#define TIM0_CTC_INTERRUPT_BIT   TIMSK,1

#define TIM0_OV_FLAG_BIT         TIFR,0
#define TIM0_CTC_FLAG_BIT        TIFR,1
*/
// TIM0_NORMAL , TIM0_PWM ,TIM0_CTC, TIM0_FAST_PWM
#define TIM0_OVERFLOW    0
#define TIM0_PWM         1
#define TIM0_CTC         2
#define TIM0_FAST_PWM    3


#define  TIM0_NO_CLK                     0
#define  TIM0_CLK_by_1                   1
#define  TIM0_CLK_by_8                   2
#define  TIM0_CLK_by_64                  3
#define  TIM0_CLK_by_256                 4
#define  TIM0_CLK_by_1024                5
#define  TIM0_EXT_CLK_ON_T0_FALLINGEDGE  6
#define  TIM0_EXT_CLK_ON_T0_RISINGEDGE   7
#endif
