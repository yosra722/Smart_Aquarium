/*
 * Ultrasonic_int.h
 *
 *  Created on: Aug 6, 2026
 *      Author: Amena El-Koussy
 */

#ifndef ULTRASONIC_INT_H_
#define ULTRASONIC_INT_H_

#include "../../LIB/STD_Types.h"

void Ultrasonic_Init(void);
u16 Ultrasonic_GetDistance(void);
void Ultrasonic_Trigger(void);

#endif /* ULTRASONIC_INT_H_ */
