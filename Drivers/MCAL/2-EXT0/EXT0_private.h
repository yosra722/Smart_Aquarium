/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 31/07/2026   ************/
/************** File  : Private File ************/
/********* Last Update: 1/08/2026   *************/
/************************************************/

#define EXT0_PRIVATE_H
#ifdef  EXT0_PRIVATE_H
 
extern pf CALLED_BACK_FUNCTION_PTR ;

#define MCUCR   *((volatile u8 *)0x55 )
#define GICR    *((volatile u8 *)0x5B )
#define GIFR    *((volatile u8 *)0x5A )
#endif
