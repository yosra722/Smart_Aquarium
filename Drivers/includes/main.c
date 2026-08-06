/*****************************************/
/******** File  : main.c              *****/
/******** Purpose: Integration/Test    *****/
/*****************************************/

#include "Bit_Math.h"
#include "STD_Types.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_int.h"
#include "GIE_int.h"
#include "EXTI_int.h"

#include "ADC_int.h"
#include "LCD_int.h"
#include "LM35_int.h"

#include "SERVO_interface.h"

#include "TIM0_int.h"
#include "TIM2_int.h"
#include "STOP_WATCH_int.h"



int main(void)
{
	/*---------------- Initialization ----------------*/

	/* Digital I/O : sets all ports/pins directions as configured in DIO_config.h */
	DIO_voidInitialization();

	/* External interrupts : reset sense modes / clear pending flags */
	EXTI_Initilization();

	/* LCD : must run after DIO init since it drives LCD pins through DIO */
	LCD_voidIntialization();

	/* ADC + LM35 temperature sensor (LM35_voidInit() calls ADC_voidInit() + ADC_voidADCEnable()) */
	LM35_voidInit();

	/* Servo motor on Timer1 PWM */
	SERVO_voidInit();

	/* Timer0-based stopwatch */
	STW_voidInitialization();

	/* Timer2 (kept initialized in case seconds_counter / PWM features are needed) */
	TIM2_voidInit();


	return 0;
}
