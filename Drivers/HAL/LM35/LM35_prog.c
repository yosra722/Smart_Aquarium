/*****************************************/
/******** Author: Yosra Madkour **********/
/******** Date  : 6/8/2026   *************/
/******** File  : Program File ***********/
/*****************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include <avr/delay.h>

#include"DIO_int.h"
#include"ADC_int.h"

#include"LM35_int.h"
#include"LM35_private.h"
#include"LM35_config.h"


void LM35_voidInit(void)
{
	DIO_voidSetPinDirection(LM35_VOUT,INPUT);
	ADC_voidInit();
	ADC_voidADCEnable();
	ADC_voidInterruptEnable();
	LCD_GotoXY(0,0);
	LCD_voidWriteMoveString("TEMP : ");
}
u16 LM35_u16GetTemp(void)
{

	ADC_voidStartConverstion();
	u16 value = ADC_u16Read();
    value = (value*500)/1024;
    if(value <= 20 && value >=0)
    {
    	ADC_voidInterruptEnable();
    	ADC_voidSetCallBack(LM35_voidINT());
    }
    return value;
}

void LM35_voidINT(void)
{

	DIO_voidSetPinDirection(PORTCID,PIN0,OUTPUT );
	DIO_voidSetPinValue(PORTCID,PIN0,HIGH);
	_delay_ms(100);
	DIO_voidSetPinValue(PORTCID,PIN0,LOW);
}
void LM35_DisplayTemp(void)
{
	LM35_voidClearTem();
	LCD_GotoXY(7,0);
	LCD_voidWriteNumber(LM35_u16GetTemp());
	LCD_voidWriteMoveString(" C");
}


static void LM35_voidClearTem(void)
{
	LCD_GotoXY(7,0);
	LCD_voidWriteMoveString("   ");
}
