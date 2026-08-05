/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 30/07/2026   ************/
/************** File  : interface File  *********/
/********* Last Update: 31/07/2026   ************/
/************************************************/

#define KEYPAD_CONFIG_H
#ifdef  KEYPAD_CONFIG_H

/*
 *  { 1   2   3   + }       { 33    23    13    03 } row3
 *  { 4   5   6   - }       { 32    22    12    02 } row2
 *  { 7   8   9   * }       { 31    21    11    01 } row1
 *  { !   0   %   / }       { 30    20    10    00 } row0
 *                           col3   col2  col1  col0
 */


void KEYPAD_voidInitializaton(void);/**GO TO SET THIS PINS AT DIO_CONFIG TO IN /OUT*/

u8   KEYPAD_u8GetPressedKey(void);
#endif
