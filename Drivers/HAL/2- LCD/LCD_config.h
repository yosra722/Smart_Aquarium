/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 29/07/2026   ************/
/************** File  : Configuration File  *****/
/********* Last Update: 30/07/2026   ************/
/************************************************/

#define LCD_CONFIG_H
#ifdef  LCD_CONFIG_H


#define LCD_RS   PORTAID,PIN1
#define LCD_RW   PORTAID,PIN2
#define LCD_EN   PORTAID,PIN3



#define LCD_D0 PORTBID,PIN0
#define LCD_D1 PORTBID,PIN1
#define LCD_D2 PORTBID,PIN2
#define LCD_D3 PORTBID,PIN3
#define LCD_D4 PORTBID,PIN4
#define LCD_D5 PORTBID,PIN5
#define LCD_D6 PORTBID,PIN6
#define LCD_D7 PORTBID,PIN7

#define SET_UP				LCD_FunctionSet_8b_2l_57
#define DISPLAY_SETUP		LCD_Display_ON_Cursor_OFF
#define ENTER_MODE			LCD_Enter_Mode_INC

#endif
