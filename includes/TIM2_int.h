/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM2 INTERFACE FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef TIM2_INTERFACE_H_
#define TIM2_INTERFACE_H_

#include "STD_TYPES.h"

/* Pointer to Function */
typedef void (*pf)(void);

/*******************************************************************************
 *                            Prototypes                                 *
 *******************************************************************************/

/* Initialization */
void TIM2_voidInit(void);

/* Normal Mode */
void TIM2_voidEnableOVInterrupt(void);
void TIM2_voidDisableOVInterrupt(void);
void TIM2_voidSetPreloadReg(u8 u8PreloadValue);
u8   TIM2_u8ReadTimerReg(void);
void TIM2_voidOVSetCallBack(pf pvOVFunctionAddress);

/* CTC Mode */
void TIM2_voidEnableCOMPInterrupt(void);
void TIM2_voidDisableCOMPInterrupt(void);
void TIM2_voidSetCompareReg(u8 u8CompareValue);
void TIM2_voidCOMPSetCallBack(pf pvCOMPFunctionAddress);

/*PWM*/
void TIM2_voidGeneratePWM(u8 u8DutyCycle);

void TIM2_voidInitFastPWMWithInterrupt(void)ß

#endif /* TIM2_INTERFACE_H_ */
