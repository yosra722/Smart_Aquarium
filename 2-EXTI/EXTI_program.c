/*
 * EXTI_program.c
 *
 *  Created on: Aug 4, 2026
 *      Author: B2B
 */

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*Ptr0)(void) = 0x00;
static void (*Ptr1)(void) = 0x00;
static void (*Ptr2)(void) = 0x00;

void EXTI_Initilization (void)
{
    CLR_BIT(GICR, INT0_BIT);
    CLR_BIT(GICR, INT1_BIT);
    CLR_BIT(GICR, INT2_BIT);

    SET_BIT(GIFR, INTF0_BIT);
    SET_BIT(GIFR, INTF1_BIT);
    SET_BIT(GIFR, INTF2_BIT);

    Ptr0 = 0x00;
    Ptr1 = 0x00;
    Ptr2 = 0x00;
}


void EXTI0_InterruptEnable (void)
{
	SET_BIT(GICR, INT0_BIT);
}

void EXTI1_InterruptEnable (void)
{
	SET_BIT(GICR, INT1_BIT);
}

void EXTI2_InterruptEnable (void)
{
	SET_BIT(GICR, INT2_BIT);
}

void EXTI0_InterruptDisable (void)
{
	CLR_BIT(GICR, INT0_BIT);
}

void EXTI1_InterruptDisable (void)
{
	CLR_BIT(GICR, INT1_BIT);
}

void EXTI2_InterruptDisable (void)
{
	CLR_BIT(GICR, INT2_BIT);
}

void EXTI0_SetSenseMode (u8 Mode)
{
	switch (Mode)
	{
	case LOW_LEVEL : CLR_BIT(MCUCR, ISC01); CLR_BIT(MCUCR, ISC00);	break;
	case ANY_CHANGE : CLR_BIT(MCUCR, ISC01); SET_BIT(MCUCR, ISC00);		break;
	case FALLING_EDGE : SET_BIT(MCUCR, ISC01); CLR_BIT(MCUCR, ISC00);	break;
	case RISING_EDGE : SET_BIT(MCUCR, ISC01); SET_BIT(MCUCR, ISC00);	break;
	default : break;
	}
}

void EXTI1_SetSenseMode (u8 Mode)
{
	switch (Mode)
	{
	case LOW_LEVEL : CLR_BIT(MCUCR, ISC11);	CLR_BIT(MCUCR, ISC10);	break;
	case ANY_CHANGE : CLR_BIT(MCUCR, ISC11);	SET_BIT(MCUCR, ISC10);	break;
	case FALLING_EDGE : SET_BIT(MCUCR, ISC11);	CLR_BIT(MCUCR, ISC10);	break;
	case RISING_EDGE : SET_BIT(MCUCR, ISC11);	SET_BIT(MCUCR, ISC10);	break;
	default : break;
	}
}

void EXTI2_SetSenseMode (u8 Mode)
{
	switch (Mode)
	{
	case FALLING_EDGE : CLR_BIT (MCUCSR, ISC2);	break;
	case RISING_EDGE : SET_BIT (MCUCSR , ISC2);	break;
	default : break;
	}
}

void EXTI0_SetCallBack (void (*Copy_pvPtrFunc)(void))
{
	Ptr0 = Copy_pvPtrFunc;
}

void EXTI1_SetCallBack (void (*Copy_pvPtrFunc)(void))
{
	Ptr1 = Copy_pvPtrFunc;
}

void EXTI2_SetCallBack (void (*Copy_pvPtrFunc)(void))
{
	Ptr2 = Copy_pvPtrFunc;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (Ptr0 != 0x00)
	{
		Ptr0();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (Ptr1 != 0x00)
	{
		Ptr1();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (Ptr2 != 0x00)
	{
		Ptr2();
	}
}
