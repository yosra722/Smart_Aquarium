/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 30/07/2026   ************/
/************** File  : Configuration File  *****/
/********* Last Update: 31/07/2026   ************/
/************************************************/

#define KEYPAD_CONFIG_H
#ifdef  KEYPAD_CONFIG_H
/*
 *  { 7   8   9   / }       { 33    23    13    03 } row3
 *  { 4   5   6   * }       { 32    22    12    02 } row2
 *  { 1   2   3   - }       { 31    21    11    01 } row1
 *  { !   0   %   + }       { 30    20    10    00 } row0
 *                           col3   col2  col1  col0
 */


#define KEYPAD_ELEMENT33_   '7'
#define KEYPAD_ELEMENT32_   '4'
#define KEYPAD_ELEMENT31_   '1'
#define KEYPAD_ELEMENT30_   '!'

#define KEYPAD_ELEMENT22_   '8'
#define KEYPAD_ELEMENT23_   '5'
#define KEYPAD_ELEMENT21_   '2'
#define KEYPAD_ELEMENT20_   '0'

#define KEYPAD_ELEMENT13_   '9'
#define KEYPAD_ELEMENT12_   '6'
#define KEYPAD_ELEMENT11_   '3'
#define KEYPAD_ELEMENT10_   '='

#define KEYPAD_ELEMENT03_   '/'
#define KEYPAD_ELEMENT02_   '*'
#define KEYPAD_ELEMENT01_   '-'
#define KEYPAD_ELEMENT00_   '+'


#define GET_ELEMENT(COL , ROW) KEYPAD_ELEMENT##COL##ROW
/**GO TO SET THIS PINS AT DIO_CONFIG TO IN /OUT*/
/**COLUMS IS OUTPUTS , ROWS IS INPUTS*/
#define KEYPAD_COL0    PORTDID,PIN0
#define KEYPAD_COL1    PORTDID,PIN1
#define KEYPAD_COL2    PORTDID,PIN2
#define KEYPAD_COL3    PORTDID,PIN3

#define KEYPAD_ROW0    PORTDID,PIN4
#define KEYPAD_ROW1    PORTDID,PIN5
#define KEYPAD_ROW2    PORTDID,PIN6
#define KEYPAD_ROW3    PORTDID,PIN7


#endif
