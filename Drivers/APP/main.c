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




#define MCUCSR   *((volatile u8*)0x54)
#define WDTCR    *((volatile u8*)0x41)
#define WDRF     0
#define WDCE     4
#define WDE      3


extern volatile u8 seconds_counter ;
u16 TEMP;
u16 LastDistance = 0;

void SERVO(void);
void Ultrasonic(void);
void LM35(void);


int main(void)
{

	MCUCSR &= ~(1 << WDRF);
	WDTCR  |= (1 << WDCE) | (1 << WDE);
	WDTCR   = 0x00;

	DIO_voidInitialization();
	EXTI_Initilization();
	LCD_voidIntialization();

	/* LM35 one-time setup: ADC init + LM35 output pin direction */
	LM35_voidInit();
	DIO_VoidSetPinDirection(PORTCID, PIN0, OUTPUT);
	DIO_voidSetPinValue(PORTCID, PIN0, LOW);

	SERVO_voidInit();
	STW_voidInitialization();
	TIM2_voidInitCTC();
	Ultrasonic_Init( );

	GIE_voidEnable();

	SERVO_voidSetAngle(0);

	while (1)
	{
		SERVO();
		Ultrasonic();
		LM35();

	}


	return 0;
}
void Ultrasonic(void)
{
	static u8 LastReadSecond = 255;


	if ((seconds_counter % 10 == 0) && (seconds_counter != LastReadSecond))
	{
		LastReadSecond = seconds_counter;

		LastDistance = Ultrasonic_GetDistance();


		LCD_GotoXY(0,1);
		LCD_voidWriteMoveString("Lvl:-");
		LCD_GotoXY(4,1);
		LCD_voidWriteMoveString("   ");
		LCD_GotoXY(4,1);
		LCD_voidWriteNumber(LastDistance);
		LCD_voidWriteMoveString("cm ");


		if (LastDistance > 10)
		{
			DIO_voidSetPinValue(PORTDID, PIN7, HIGH);

			while (Ultrasonic_GetDistance() > 4)
			{
				_delay_ms(1000);
			}

			DIO_voidSetPinValue(PORTDID, PIN7, LOW);
		}
	}
}
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
void SERVO(void)
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
}
