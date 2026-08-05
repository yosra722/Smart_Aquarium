/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 31/07/2026   ************/
/************** File  : Program File  ***********/
/********* Last Update: 1/08/2026   *************/
/************************************************/

#include "Bit_Math.h"
#include "STD_Types.h"

#include "DIO_int.h"
#include "GIE_int.h"

#include "EXT0_int.h"
#include "EXT0_config.h"
#include "EXT0_private.h"

pf CALLED_BACK_FUNCTION_PTR;

 void EXT0_voidInitilaization(void)
 {
	 /** 
	 	 1- clear flag
	 	 2- set sence mode
	 	 3- clear enable mode
	 	 4- PORTD pin2 set to input #define INT0_PIN   PORTDID , PIN2
	 	 */
	 EXT0_voidSetSignalCritera(DEFAULE_SENCE_MODE);
	 EXT0_voidInterruptDisable(); // CLEAR FLAG + CLEAR ENABLE
	 //DIO_VoidSetPinDirection (INT0_PIN ,INPUT);

 }

void EXT0_voidInterruptEnable(void)
{
	/**
	1- set GIE to Bit enable 
	2- clear flag at GIFR  Bit 6 –-> INTF0 , Bit 7 –-> INTF1 ,Bit 5 –-> INTF2
	3- set int0 bit at GICR (enable bit)
	*/
	GIE_voidEnable();
	SET_BIT(GICR, 6);
	CLR_BIT(GIFR, 6);
}

void EXT0_voidInterruptDisable(void)
{
	/**
	  CONNECT GICR TO ITS ADDRESS AT CONFIG
	 1- clear flag  GIFR  Bit 6 –-> INTF0 , Bit 7 –-> INTF1 ,Bit 5 –-> INTF2
	 3- clear int0 bit at GICR enable bit 6 --> INT0 , 7--> INT1 , 5-->INT2
	 */
	CLR_BIT(GICR, 6);
	CLR_BIT(GIFR, 6);
}

void EXT0_voidSetSignalCritera(u8 u8SensMode)
{
	/**
	CONNECT MCUCR TO ITS ADDRESS AT CONFIG
	select trigger type from MCUCR 
	Bit 1 and 0 for EXT_INT0
	Bit 3 and 2 for EXT_INT1
	*/
	/* u8SensMode --> 00  -> 0 ->low level
	 *            --> 01  -> 1 ->Any logical change
	 *            --> 10  -> 2 ->falling edge
	 *            --> 11  -> 3 ->rising edge  */

	switch (u8SensMode)
	{
	case LOW_LEVEL_MODE          : CLR_BIT(MCUCR,0); CLR_BIT(MCUCR,1); break;
	case ANY_LOGICAL_CHANGE_MODE : SET_BIT(MCUCR,0); CLR_BIT(MCUCR,1); break;
	case FALLING_EDGE_MODE       : CLR_BIT(MCUCR,0); SET_BIT(MCUCR,1); break;
	case RISING_EDGE_MODE        : SET_BIT(MCUCR,0); SET_BIT(MCUCR,1); break;
	default : break ;
	}
}
void EXT0_voidSetCallBack (pf FunctionAddress)
 {
	 /**
	 1- create typedef for pointer to fun //typedef void  (*pf)   (void);
	 2- create static pointerto fun variable and put the funaddress on it
	 */
	 CALLED_BACK_FUNCTION_PTR = FunctionAddress ;
 }


void __vector_1 (void)__attribute__((signal,used));
void __vector_1 (void)
{

	// Action of Interrupt
	CALLED_BACK_FUNCTION_PTR();
}
