/************************************************/
/********* Author: Khadija Naji *****************/
/********* Date  : 29/07/2026   *****************/
/********* File  : Interface File  **************/
/************************************************/
#ifndef  DIO_INT_H
#define  DIO_INT_H
//#include "STD_Types.h"
 /** PORTs ID */
#define PORTAID 0
#define PORTBID 1
#define PORTCID 2
#define PORTDID 3

 /** PINSs ID */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0
#define ON   1
#define OOF  0

/**set all pins to initial value determined at configration*/
void DIO_voidInitialization    (void); 

/*********************Pin set*************************/
void DIO_VoidSetPinDirection   (u8 portID , u8 pinID , u8 Direction);
/**output mode*/
void DIO_voidSetPinValue       (u8 portID , u8 pinID , u8 value);
void DIO_voidTogglePin         (u8 PortID , u8 PinID);
/**input mode*/
u8   DIO_u8GetPinValue         (u8 PortID , u8 PinID);

/*********************Port set*************************/
void DIO_voidSetPortDirection  (u8 PortID, u8 Direction);
void DIO_voidSetPortValue      (u8 PortID, u8 Value);


#endif
