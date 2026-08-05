/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 29/07/2026   ************/
/************** File  : Private File  ***********/
/********* Last Update: 30/07/2026   ************/
/************************************************/
#ifndef  LCD_PRIVATE_H
#define  LCD_PRIVATE_H

#define LCD_CLEAR            0X01
#define LCD_HOME             0x02 //SET CURSER TO FISRT POSITION_FIRST LINE , FISRT CHAR
#define LCD_ENTRRY_MODE      0X06
#define LCD_DISPLAYOOF       0X08
#define LCD_DISPLAYON        0X0C
#define LCD_FUNCTION_RESET   0X30 //RESET LED 
#define LCD_FUNCTION_8BIT    0X38 //SMALL THE SIZE OF DISPLAYED CHAR , 2 LINE DISPLAY ; CHAR-->5*7 INSTED OF 5*10
#define LCD_SETCURSER        0X80 //SET CURSER POSITION


#define LCD_SHIFTCURSOR_LEFT   0x10
#define LCD_SHIFTCURSOR_RIGHT  0x14

#define LCD_SHIFTDISPLAY_LEFT  0x18
#define LCD_SHIFTDISPLAY_RIGHT 0x1C



static void LCD_voidPutonBus(u8 u8char);
static u8* LCD_dec_to_arrOfChar(u16 u16Number);

#endif
