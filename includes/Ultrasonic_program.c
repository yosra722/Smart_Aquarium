/*
 * Ultrasonic_program.c
 *
 *  Created on: Aug 6, 2026
 *      Author: Amena El-Koussy
 */

#include "STD_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "GIE_int.h"
#include "STOP_WATCH_int.h"
#include <util/delay.h>

#include "Ultrasonic_config.h"
#include "Ultrasonic_int.h"


static volatile u16 Echo_Time=0;
static volatile u8 Flag =0;
void Ultrasonic_ISR();

void Ultrasonic_Init(void)
{
	DIO_VoidSetPinDirection(TRIGGER_PORT, TRIGGER_PIN, OUTPUT);
	DIO_VoidSetPinDirection(ECHO_PORT, ECHO_PIN, INPUT);
	EXTI0_SetCallBack (Ultrasonic_ISR);
	EXTI0_SetSenseMode (ANY_CHANGE);
	EXTI0_InterruptEnable ();
}

 void Ultrasonic_Trigger(void)
{
	DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN, LOW);
}

u16 Ultrasonic_GetDistance(void)
{
    Ultrasonic_Trigger();

    while(Flag == 0);

    Flag = 0;

    return (Echo_Time / 58);
}

void Ultrasonic_ISR()
{
	if(DIO_u8GetPinValue(ECHO_PORT, ECHO_PIN)==1)
	{
		STW_voidStart();
		Flag=0;
	}
	else
	{
		Echo_Time= STW_u16StopANDWatch_usec();
		Flag = 1;
	}
}
