/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : SERVO PRIVATE FILE                             */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef SERVO_PRIVATE_H
#define SERVO_PRIVATE_H

/*
TIM1 REGISTERS ADDRESSES
*/

#define TCCR1A_REG  *((volatile u8*)0x4F)
#define TCCR1B_REG  *((volatile u8*)0x4E)

#define ICR1_REG     *((volatile u16*)0x46)
#define OCR1A_REG    *((volatile u16*)0x4A)
#define OCR1B_REG    *((volatile u16*)0x48)

/*
TCCR1A BITS
*/
#define COM1A1_BIT      7
#define COM1A0_BIT      6
#define COM1B1_BIT      5
#define COM1B0_BIT      4
#define WGM11_BIT       1
#define WGM10_BIT       0

/*
TCCR1B BITS
*/
#define WGM13_BIT      4
#define WGM12_BIT      3
#define CS12_BIT       2
#define CS11_BIT       1
#define CS10_BIT       0


#define SERVO_CHANNEL_A     1
#define SERVO_CHANNEL_B     2

#define SERVO_TIMER1_TOP_VALUE  20000UL



#endif /*SERVO_PRIVATE_H*/