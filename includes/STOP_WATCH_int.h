/************************************************/
/************** Author: Khadija Naji ************/
/************** File  : Interface File  *********/
/************************************************/

#define STOP_WATCH_INT_H
#ifdef  STOP_WATCH_INT_H
//depend on TIM0
void STW_voidInitialization(void) ;
void STW_voidStart(void);        //start count

/************** Microsecond *********/
u16  STW_u16StopANDWatch_usec(void);  // Stop counting and init STW
u16  STW_u16Watch__usec(void);         //counting will continue _usec== microsecond

/************** Millisecond *********/

u32  STW_u32StopANDWatch_msec(void);
u32  STW_u32Watch_msec(void);
/************** Second *********/

u16  STW_u16StopANDWatch_sec(void);
u16  STW_u16Watch_sec(void);

#endif
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
