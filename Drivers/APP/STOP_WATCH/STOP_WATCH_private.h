/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 06/08/2026   *************/
/************** File  : Private  File  **********/
/********* Last Update: 06/08/2026   ************/
/************************************************/

#define STOP_WATCH_PRIVATE_H
#ifdef  STOP_WATCH_PRIVATE_H


static void TIM0_voidCallback(void);
static u32 TIM0_u32ConvertFromCountstoMicrosecound(u16 OV_counts , u16 u16CurrentRegValue );


#if      PERSCALLER_MODE == TIM0_CLK_by_1
    #define TICK_PRESCALER_REAL_VALUE   1
#elif    PERSCALLER_MODE == TIM0_CLK_by_8
    #define TICK_PRESCALER_REAL_VALUE   8
#elif    PERSCALLER_MODE == TIM0_CLK_by_64
    #define TICK_PRESCALER_REAL_VALUE   64
#elif    PERSCALLER_MODE == TIM0_CLK_by_256
    #define TICK_PRESCALER_REAL_VALUE   256
#elif    PERSCALLER_MODE == TIM0_CLK_by_1024
    #define TICK_PRESCALER_REAL_VALUE   1024
#else
    #define TICK_PRESCALER_REAL_VALUE   1
#endif

#define TICK_TIME_USEC   ((TICK_PRESCALER_REAL_VALUE * 1000000 ) / F_CPU)


#endif

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
