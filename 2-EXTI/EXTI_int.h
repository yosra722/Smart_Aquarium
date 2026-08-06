/*
 * EXTI_int.h
 *
 *  Created on: Aug 4, 2026
 *      Author: Amena hassan
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include "../../LIB/STD_Types.h "

#define	LOW_LEVEL		0
#define	ANY_CHANGE		1
#define	FALLING_EDGE	2
#define	RISING_EDGE		3


void EXTI_Initilization (void);

void EXTI0_InterruptEnable (void);
void EXTI1_InterruptEnable (void);
void EXTI2_InterruptEnable (void);

void EXTI0_InterruptDisable (void);
void EXTI1_InterruptDisable (void);
void EXTI2_InterruptDisable (void);

void EXTI0_SetSenseMode (u8 mode);
void EXTI1_SetSenseMode (u8 mode);
void EXTI2_SetSenseMode (u8 mode);

void EXTI0_SetCallBack (void (*Copy_pvPtrFunc) (void));
void EXTI1_SetCallBack (void (*Copy_pvPtrFunc) (void));
void EXTI2_SetCallBack (void (*Copy_pvPtrFunc) (void));

#endif /* EXTI_INT_H_ */
