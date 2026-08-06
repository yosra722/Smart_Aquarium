/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 29/07/2026   ************/
/************** File  : Program File  ***********/
/********* Last Update: 30/07/2026   ************/
/************************************************/
#include "Bit_Math.h"
#include "STD_Types.h"

#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include <avr/delay.h>

void LCD_voidIntialization(void)
{
	/**
	FROM DATASHEET
	1- wait 30 ms
	2- send home command // beraga3 el cursur le awel el sater zay alet el ketaba el adema
	3- send command fun set 8 BIT COMMAND      wait 1 ms     wait 1 ms
	4- send display on/off command  wait 1   ms
	5- send display clear command   wait 1.5 ms
	6- send Enty Mode command
	*/
	_delay_ms(35);// 35 beacouse 30 is the min   //1

	LCD_voidSendCommand(LCD_HOME);               //2
	_delay_ms(1);

	LCD_voidSendCommand(SET_UP);      //3
	_delay_ms(1);

	LCD_voidSendCommand(LCD_Display_OFF);         //4
	LCD_voidSendCommand(DISPLAY_SETUP);
	_delay_ms(1);

	LCD_voidSendCommand(LCD_CLEAR);              //5
	_delay_ms(2);

	LCD_voidSendCommand(ENTER_MODE);        //6

}

void LCD_voidSendCommand( u8 u8CMD)
{
	DIO_voidSetPinValue(LCD_RS, LOW);
	DIO_voidSetPinValue(LCD_RW, LOW);

	LCD_voidPutonBus(u8CMD);
}
void LCD_voidSendData( u8 u8CMD)
{
	DIO_voidSetPinValue(LCD_RS, HIGH);
	DIO_voidSetPinValue(LCD_RW, LOW);

	LCD_voidPutonBus(u8CMD);

}
void LCD_GotoXY(u8 X, u8 Y)
{
	/** 0000 0000
	    1yxx xxxx
		total DDRRAM address in dec = (128) +(64*y) + x ;
		LDC_GO_DDRRAM_ADDRESS(X,Y)
		TO make it faster code define all addresses command value at array
	    u8 DDRRAM_arr[16][2] = {{0x80,0x81,...,0x8F},{0xC0,...,0xCF}}
		DDRRAM_arr[X][Y]
	*/
     /** LINE HAVE 40 CHAR LOCATIN BUT
	 ONLY 16 IS DISPLAYABLE , SO WE CAN
	 WRITE AT HIDDEN LOCATIONSO ,
	 USED AT APP LIKE WRITE A LARGE Sentence
	 OR MAKE THE DISPLY MOVABLE
	 */

	if( X < 40 && Y < 2 )
		LCD_voidSendCommand( LCD_GO_DDRRAM_ADDRESS(X,Y));
	else
		LCD_voidSendCommand( LCD_HOME);
}


/** Comment EDIT THIS
to can hanlde the full word should be in the same line

 or make it moved if u wanna display in the same line
*/
void LCD_voidWriteString(u8* u8string , u8 line)
{
	LCD_voidSendCommand(LCD_HOME);
	if (line <2)
	{
		u8 counter=0 ;
	if (line ==1)
	{
		LCD_GotoXY(0, 1);
	}
	while ( u8string[counter] != '\0')
	{
		LCD_voidSendData( u8string[counter]);
		         //LCD_voidSendCommand(LCD_SHIFTCURSOR_RIGHT);
		/**LCD automatic shift the curser*/
		counter++;
		if (counter ==16)
		{
			LCD_voidSendCommand(LCD_GO_DDRRAM_ADDRESS(0,1)) ;
		}
	}
	}else
	{
		//NO Code
	}

}

void LCD_voidWriteNumber(u16 u16Number)
{
    u8 v[5];
    u8 i;
    for(i=0;i<5;i++){
        if(u16Number==0){
            v[i]='\0';
            break;
        }
        else {
            v[i]=(u16Number%10)+'0';
            u16Number /=10;
        }
    }
    while(i > 0 )
    {
        LCD_voidSendData(v[--i]);
    }
}

/*static u8* LCD_dec_to_arrOfChar(u16 u16Number)
{
	u8 * res ;
	return res ;
}
*/
void LCD_voidWriteMoveString(u8* u8string)
{
    u8 counter=0;
	while(u8string[counter]!='\0'){
		LCD_voidSendData(u8string[counter]);
		counter++;
	}
}


static void LCD_voidPutonBus(u8 u8char)
{
	DIO_voidSetPinValue(LCD_D0 ,Get_Bit(u8char,0));
	DIO_voidSetPinValue(LCD_D1 ,Get_Bit(u8char,1));
	DIO_voidSetPinValue(LCD_D2 ,Get_Bit(u8char,2));
	DIO_voidSetPinValue(LCD_D3 ,Get_Bit(u8char,3));
	DIO_voidSetPinValue(LCD_D4 ,Get_Bit(u8char,4));
	DIO_voidSetPinValue(LCD_D5 ,Get_Bit(u8char,5));
	DIO_voidSetPinValue(LCD_D6 ,Get_Bit(u8char,6));
	DIO_voidSetPinValue(LCD_D7 ,Get_Bit(u8char,7));

	DIO_voidSetPinValue(LCD_EN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_EN, LOW);
	_delay_ms(2);
}
