/*
 * ServoMotor.c
 *
 * Created: 8/5/2026 8:46:22 PM
 * Author : Heisenberg
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.H"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SERVO_interface.h"



int main(void)
{
	SERVO_voidInit();
	
    while (1) 
    {
		Servo_voidSetAngle(0);
		_delay_ms(1500);
		
		Servo_voidSetAngle(90);
		_delay_ms(1500);

		Servo_voidSetAngle(180);
		_delay_ms(1500);
    }
}

