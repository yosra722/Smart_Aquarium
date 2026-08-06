/*****************************************/
/******** Author: Yosra Madkour **********/
/******** Date  : 6/8/2026   *************/
/******** File  : Program File ***********/
/*****************************************/

#include "Bit_Math.h"
#include "STD_Types.h"
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
	LCD_GotoXY(0,0);
}
u16 LM35_u16GetTemp(void)
{
	ADC_voidStartConverstion();
	u16 TEMP=ADC_u16Read();
    TEMP = (TEMP*500)/1024;
    return TEMP;
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
