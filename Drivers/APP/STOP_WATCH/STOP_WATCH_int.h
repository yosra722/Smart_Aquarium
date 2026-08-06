/************************************************/
/************** Author: Khadija Naji ************/
/************** File  : Interface File  *********/
/************************************************/

#define STOP_WATCH_INT_H
#ifdef  STOP_WATCH_INT_H
//depend on TIM0
void STW_voidInitialization(void) ;
void STW_voidStart(void);        //start count

u16 STW_u16StopANDWatch_usec(void);    // Stop counting and init STW


#endif
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
