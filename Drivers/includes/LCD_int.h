/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 29/07/2026   ************/
/************** File  : Interface File  *********/
/********* Last Update: 30/07/2026   ************/
/************************************************/
#ifndef  LCD_INT_H
#define  LCD_INT_H

#define LCD_GO_DDRRAM_ADDRESS(X,Y)  128+(64*Y)+X

void LCD_voidIntialization(void);
void LCD_voidSendData( u8 u8CMD);
void LCD_voidSendCommand( u8 u8CMD);
void LCD_GotoXY(u8 X, u8 Y);

void LCD_voidWriteString(u8 * u8string , u8 line);
void LCD_voidWriteMoveString(u8 * u8string);
void LCD_voidWriteNumber(u16 u16Number);

#endif
