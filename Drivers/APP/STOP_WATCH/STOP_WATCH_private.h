/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 06/08/2026   *************/
/************** File  : Private  File  **********/
/********* Last Update: 06/08/2026   ************/
/************************************************/

#define STOP_WATCH_PRIVATE_H
#ifdef  STOP_WATCH_PRIVATE_H


static void TIM0_voidCallback(void);
static u16 TIM0_u16ConvertFromCountstoMicrosecound(u16 OV_counts , u16 u16CurrentRegValue );

#define TICK_TIME_nSEC   ((PERSCALLER_MODE *1000000000 ) / F_CPU)
#endif

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
