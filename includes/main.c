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



extern volatile u8 seconds_counter ;

int main(void)
{
	GIE_voidEnable();

	DIO_voidInitialization();

	EXTI_Initilization();

	LCD_voidIntialization();

	LM35_voidInit();

	SERVO_voidInit();


	STW_voidInitialization();


	TIM2_voidInitFastPWMWithInterrupt();
	SERVO_voidSetAngle(0);

	while (1)
	{
		if(seconds_counter == 60)
		{
			SERVO_voidSetAngle(180);
			_delay_ms(2000);
			SERVO_voidSetAngle(0);
		}else if(seconds_counter >= 120)
		{
			SERVO_voidSetAngle(180);
			seconds_counter=0;
			_delay_ms(2000);
			SERVO_voidSetAngle(0);

		}
	}


	return 0;
}
