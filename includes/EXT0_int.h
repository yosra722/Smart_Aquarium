/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 31/07/2026   ************/
/************** File  : Interface File  *********/
/********* Last Update: 1/08/2026   *************/
/************************************************/

#define EXT0_INT_H
#ifdef  EXT0_INT_H

//set INT0 pin to input
 void EXT0_voidInitilaization(void);
 
 void EXT0_voidInterruptEnable(void);
 
 void EXT0_voidInterruptDisable(void);
 
 void EXT0_voidSetSignalCritera(u8 u8SensMode);
 
 void EXT0_voidSetCallBack (pf FunctionAddress);
#define LOW_LEVEL_MODE            0
#define ANY_LOGICAL_CHANGE_MODE   1
#define FALLING_EDGE_MODE         2
#define RISING_EDGE_MODE          3

#define DEFAULE_SENCE_MODE ANY_LOGICAL_CHANGE_MODE
#endif
