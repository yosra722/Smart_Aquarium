/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 30/07/2026   ************/
/************** File  : Program File  ***********/
/********* Last Update: 31/07/2026   ************/
/************************************************/

#include "Bit_Math.h"
#include "STD_Types.h"

#include "DIO_int.h"

#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"



void KEYPAD_voidInitializaton(void)
{
	/**set all pins port to 1 (output(colums) and inputs(rows)*/

	/**********************************************/
	/** ACTIVATE PULL UP RESISTANS FOR INPUTS */
	DIO_voidSetPinValue(KEYPAD_ROW0 , HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW1 , HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW2 , HIGH);
	DIO_voidSetPinValue(KEYPAD_ROW3 , HIGH);

	/**OUTPUTS*/
	DIO_voidSetPinValue(KEYPAD_COL0 , HIGH);
	DIO_voidSetPinValue(KEYPAD_COL1 , HIGH);
	DIO_voidSetPinValue(KEYPAD_COL2 , HIGH);
	DIO_voidSetPinValue(KEYPAD_COL3 , HIGH);
}
u8   KEYPAD_u8GetPressedKey(void)
{
	u8 RowsValue ;
	u8 pressedKey = 0xFF ;
	/******colume3 ******/
	KEYPAD_voidSetColsPortValue(0b00000111);
	RowsValue = KEYPAD_u8GetRowsValue( );

	switch(RowsValue)
	{
	case 0b00000111 : pressedKey = KEYPAD_ELEMENT33_ ; break;
	case 0b00001011 : pressedKey = KEYPAD_ELEMENT32_ ; break;
	case 0b00001101 : pressedKey = KEYPAD_ELEMENT31_ ; break;
	case 0b00001110 : pressedKey = KEYPAD_ELEMENT30_ ; break;
	default :  break;
	}

    /******colume2 ******/
    KEYPAD_voidSetColsPortValue(0b00001011);
    RowsValue = KEYPAD_u8GetRowsValue( );

    switch(RowsValue)
    {
    case 0b00000111 : pressedKey = KEYPAD_ELEMENT23_ ; break;
    case 0b00001011 : pressedKey = KEYPAD_ELEMENT22_ ; break;
    case 0b00001101 : pressedKey = KEYPAD_ELEMENT21_ ; break;
    case 0b00001110 : pressedKey = KEYPAD_ELEMENT20_ ; break;
    default :  break;
    }
    /******colume1 ******/
	KEYPAD_voidSetColsPortValue(0b00001101);
	RowsValue = KEYPAD_u8GetRowsValue( );

	switch(RowsValue)
	{
	case 0b00000111 : pressedKey = KEYPAD_ELEMENT13_ ; break;
	case 0b00001011 : pressedKey = KEYPAD_ELEMENT12_ ; break;
	case 0b00001101 : pressedKey = KEYPAD_ELEMENT11_ ; break;
	case 0b00001110 : pressedKey = KEYPAD_ELEMENT10_ ; break;
	default :  break;
	}
	/******colume0 ******/
	KEYPAD_voidSetColsPortValue(0b00001110);
	RowsValue = KEYPAD_u8GetRowsValue( );

	switch(RowsValue)
	{
	case 0b00000111 : pressedKey = KEYPAD_ELEMENT03_ ; break;
	case 0b00001011 : pressedKey = KEYPAD_ELEMENT02_ ; break;
	case 0b00001101 : pressedKey = KEYPAD_ELEMENT01_ ; break;
	case 0b00001110 : pressedKey = KEYPAD_ELEMENT00_ ; break;
	default :  break;
	}

	return pressedKey ;
}
static void KEYPAD_voidSetColsPortValue(u8 u8colsValues)
{
	DIO_voidSetPinValue (KEYPAD_COL0 , (u8colsValues & 1));     // 0111 & 0001 = 1
	DIO_voidSetPinValue (KEYPAD_COL1 , ((u8colsValues>>1) & 1));// 0011 & 0001 =1
	DIO_voidSetPinValue (KEYPAD_COL2 , ((u8colsValues>>2) & 1));
	DIO_voidSetPinValue (KEYPAD_COL3 , ((u8colsValues>>3) & 1));

}
static u8 KEYPAD_u8GetRowsValue(void)
 {
	 u8 Rowsvalue;
	 Rowsvalue  = DIO_u8GetPinValue(KEYPAD_ROW0);
	 Rowsvalue |= (DIO_u8GetPinValue(KEYPAD_ROW1)<<1);
	 Rowsvalue |= (DIO_u8GetPinValue(KEYPAD_ROW2)<<2);
	 Rowsvalue |= (DIO_u8GetPinValue(KEYPAD_ROW3)<<3);
	 return Rowsvalue ;

 }
