/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 31/07/2026   ************/
/************** File  : Configuration File  *****/
/********* Last Update: 1/08/2026   *************/
/************************************************/

#define EXT0_CONFIG_H
#ifdef  EXT0_CONFIG_H

/* u8SensMode --> 00  -> 0 ->low level
	 *            --> 01  -> 1 ->Any logical change
	 *            --> 10  -> 2 ->falling edge
	 *            --> 11  -> 3 ->rising edge

*/

#define INT0_PIN   PORTDID , PIN2

#endif
