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


/*ENTER_MODES*/
#define LCD_Enter_Mode_INC  					0x06
#define LCD_Enter_Mode_DEC  					0x04
#define LCD_Enter_Mode_INC_Shift 				0x07
#define LCD_Enter_Mode_DEC_Shift  				0x05


/*DISPLAY_MODES*/
#define LCD_Display_OFF  						0x08
#define LCD_Display_ON_Cursor_OFF  				0x0C
#define LCD_Display_ON_Cursor_ON_Blink_OFF  	0x0E
#define LCD_Display_ON_Cursor_ON_Blink_ON   	0x0F

/*FUNCTION_SET*/
#define LCD_FunctionSet_8b_1l_57  				0x30
#define LCD_FunctionSet_8b_1l_510 				0x34
#define LCD_FunctionSet_8b_2l_57  				0x38
#define LCD_FunctionSet_8b_2l_510 				0x3C

#define LCD_FunctionSet_4b_1l_57  				0x20
#define LCD_FunctionSet_4b_1l_510 				0x24
#define LCD_FunctionSet_4b_2l_57  				0x28
#define LCD_FunctionSet_4b_2l_510 				0x2C

#define LCD_SETCURSER        0X80 //SET CURSER POSITION

/*CURSOR_MODE*/
#define LCD_SHIFTCURSOR_LEFT   0x10
#define LCD_SHIFTCURSOR_RIGHT  0x14

#define LCD_SHIFTDISPLAY_LEFT  0x18
#define LCD_SHIFTDISPLAY_RIGHT 0x1C

#define Second_Row							     0xC0

static void LCD_voidPutonBus(u8 u8char);
static u8* LCD_dec_to_arrOfChar(u16 u16Number);

#endif
