/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 06/08/2026   ************/
/************** File  : Interface File  *********/
/********* Last Update: 06/08/2026   ************/
/************************************************/

#define STOP_WATCH_INT_H
#ifdef  STOP_WATCH_INT_H
//depend on TIM0
void STW_voidInitialization(void) ;
void STW_voidStart(void);        //start count
u16  STW_u16StopANDWatch_usec(void);  // Stop counting and init STW
u16  STW_u16Watch__usec(void);         //counting will continue _usec== microsecond

#endif
