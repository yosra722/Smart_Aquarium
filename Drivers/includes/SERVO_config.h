/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : SERVO CONFIG  FILE                             */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

/*
CHANNELS:
SERVO_CHANNEL_A     
SERVO_CHANNEL_B 
 */
#define  SERVO_CHANNEL      SERVO_CHANNEL_A


#define SERVO_MIN_PULSE_TICKS       1000UL
#define SERVO_MAX_PULSE_TICKS       2000UL

#define SERVO_MAX_ANGLE             180

#endif
