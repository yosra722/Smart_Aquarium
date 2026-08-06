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

#include "TIM0_int.h"
#include "TIM2_int.h"
#include "STOP_WATCH_int.h"

#include "ADC_int.h"
#include "LCD_int.h"
#include "LM35_int.h"

#include "SERVO_interface.h"


/*---------------------------------------------------------*/
/* Watchdog-related registers (ATmega32) - defined manually,
 * same style as the rest of the project (no ready-made lib) */
/*---------------------------------------------------------*/
#define MCUCSR   *((volatile u8*)0x54)
#define WDTCR    *((volatile u8*)0x41)
#define WDRF     0
#define WDCE     4
#define WDE      3


extern volatile u8 seconds_counter ;
u16 TEMP;

/* Runs the LM35 monitoring logic (called every loop iteration).
 * NOTE: only the "poll + act" part belongs here.
 * One-time setup (ADC/DIO init) is done once in main() before the loop. */
void LM35(void)
{
	if(TEMP <= 20)
	{
		DIO_voidSetPinValue(PORTCID, PIN0, HIGH);
	}
	else
	{
		DIO_voidSetPinValue(PORTCID, PIN0, LOW);
	}

	if(TEMP != LM35_u16GetTemp())
	{
		TEMP = LM35_u16GetTemp();
		LM35_DisplayTemp();
	}
}



int main(void)
{
	/* Disable Watchdog Timer immediately at startup
	 * (must be the very first thing done, or a leftover/default-enabled
	 * WDT will keep resetting the MCU every couple of seconds) */
	MCUCSR &= ~(1 << WDRF);
	WDTCR  |= (1 << WDCE) | (1 << WDE);
	WDTCR   = 0x00;

	DIO_voidInitialization();
	EXTI_Initilization();
	LCD_voidIntialization();

	/* LM35 one-time setup: ADC init + LM35 output pin direction */
	LM35_voidInit();
	DIO_voidSetPinDirection(PORTCID, PIN0, OUTPUT);
	DIO_voidSetPinValue(PORTCID, PIN0, LOW);

	SERVO_voidInit();
	STW_voidInitialization();
	TIM2_voidInitCTC();

	GIE_voidEnable();

	SERVO_voidSetAngle(0);

	while (1)
	{

		if(seconds_counter == 60)
		{
			SERVO_voidSetAngle(180);
			_delay_ms(3000);
			SERVO_voidSetAngle(0);
		}else if(seconds_counter >= 120)
		{
			SERVO_voidSetAngle(180);
			seconds_counter=0;
			_delay_ms(3000);
			SERVO_voidSetAngle(0);
		}

		LM35();
	}


	return 0;
}
