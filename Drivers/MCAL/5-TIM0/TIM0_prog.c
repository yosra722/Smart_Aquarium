/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 03/08/2026   ************/
/************** File  : Program File  ***********/
/********* Last Update: 03/08/2026   ************/
/************************************************/

#include "Bit_Math.h"
#include "STD_Types.h"
#include "util/delay.h"

#include "TIM0_int.h"
#include "TIM0_config.h"
#include "TIM0_private.h"

/********************************************************************/
static pf FunctionAddress1;
static pf FunctionAddress2;

void TIM0_voidInitialization(void)
{
	//Select Prescaller
	TIM0_voidSetPerscaller(TIM0_PRESCALLER);
    //Select Mode  // TIM0_NORMAL , TIM0_PWM ,TIM0_CTC, TIM0_FAST_PWM
#if      TIM0_MODE ==  TIM0_FAST_PWM
	SET_BIT(TCCR0,6);//0     //10
	SET_BIT(TCCR0,3);//1     //11
#elseif  TIM0_MODE ==  TIM0_CTC
	CLR_BIT(TCCR0,6);//0    // 10
	SET_BIT(TCCR0,3);//1    // 10
#elseif  TIM0_MODE ==  TIM0_PWM
	SET_BIT(TCCR0,6);//0    // 10
	CLR_BIT(TCCR0,3);//1    // 01
#elseif  TIM0_MODE ==  TIM0_NORMAL
	CLR_BIT(TCCR0,6);//0    // 10
	CLR_BIT(TCCR0,3);//1    // 00
#endif

//Clear Bit 4 -5
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

//Clear overflow flag
	CLR_BIT(TIFR,0);
//Clear on Compare match flag
	CLR_BIT(TIFR,1);

//disable overflow interrupt
	TIM0_voidDisableOVInterrupt();
//disable on Compare match interrupt
	TIM0_voidDisableCTCInterrupt( );


//Clear TCNT0
	TIM0_voidSetOVReg(0x00);
//Clear OCR
	TIM0_voidSetCTCReg(0x00);
}

void TIM0_voidSetPerscaller(u8 u8TIM0Prescaller)
{
	if (u8TIM0Prescaller< 8)
	{
		TCCR0 = (TCCR0 & 0xF8) | (u8TIM0Prescaller) ;
	}
	else
	{
	//NO CODE
	}

}
/*****************NORMAL Mode*****************/
// to Enable the interrupt of Over flow
void TIM0_voidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK,0);
	CLR_BIT(TIFR,0);
}

// to Disable the interrupt of Over flow
void TIM0_voidDisableOVInterrupt(void)
{
	CLR_BIT(TIMSK,0);
	CLR_BIT(TIFR,0);
}

//to Set the overflow Register(TCNT0) with specificValue
void TIM0_voidSetOVReg(u8 u8OVRegValue)
{
	SET_BYTE(TCNT0,u8OVRegValue);
}

//to read the overflow Register(TCNT0)
u8 TIM0_u8ReadOVReg(void)
{
	return TCNT0;
}

/********************CTC Mode*****************/
// to Enable the interrupt of CTC
void TIM0_voidEnableCTCInterrupt(void)
{
	SET_BIT(TIMSK,1);
	CLR_BIT(TIFR,1);
}

// to Disable the interrupt of CTC
void TIM0_voidDisableCTCInterrupt(void)
{
	CLR_BIT(TIMSK,1);
	CLR_BIT(TIFR,1);
}

//to Set the CTC Register(OCR0) with specificValue
void TIM0_voidSetCTCReg(u8 u8CTCRegValue)
{
	SET_BYTE(OCR0,u8CTCRegValue);
}

//to read the CTC Register(OCR0)
u8 TIM0_u8ReadCTCCTCReg(void)
{
	return OCR0;
}



/*******************************/
//Normal Mode

void TIM0_voidOVSetCallBack(pf OVFunctionAddress)
{
	FunctionAddress1 = OVFunctionAddress;
}
//to Set theCall Back Function ofOverflow
void __vector_11(void)  __attribute__((signal, used));
void __vector_11(void)
{
	FunctionAddress1();
}

/********************************************************************************/
//CTC Mode

void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress)
{
	FunctionAddress2 = CTCFunctionAddress;
}
//to Set theCall Back Function ofOverflow
//for On Compare Match
void __vector_10(void)  __attribute__((signal, used));
void __vector_10(void)
{
	FunctionAddress2();
}

