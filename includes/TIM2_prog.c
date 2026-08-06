/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM2 PROGRAM FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#include "Bit_Math.h"
#include "STD_Types.h"
#include <stddef.h>

#include "TIM2_private.h"
#include "TIM2_config.h"
#include "TIM2_int.h"




/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

static pf TIM2_pvOVFCallBackFunc  = NULL;
static pf TIM2_pvCOMPCallBackFunc = NULL;
static u16 overflow_counter = 0;
static u16 millis_counter = 0;   /* used by TIM2_voidInitCTC for the 1ms tick */
volatile u8 seconds_counter = 0; /* Global time counter for main.c */

void TIM2_voidInit(void)
{
	#if TIM2_MODE == TIM2_NORMAL_MODE
	CLR_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);

	#elif TIM2_MODE == TIM2_CTC_MODE
	CLR_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);

	#elif TIM2_MODE == TIM2_FAST_PWM_MODE
	SET_BIT(TCCR2, WGM21);
	SET_BIT(TCCR2, WGM20);

	#if FAST_PWM_MODE == TIM2_PWM_NON_INVERTING
	CLR_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	#elif FAST_PWM_MODE == TIM2_PWM_INVERTING
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	#elif FAST_PWM_MODE == TIM2_PWM_DISCONNECTED
	CLR_BIT(TCCR2, COM20);
	CLR_BIT(TCCR2, COM21);
	#endif
	#endif

	CLR_BIT(TIMSK, TOIE2);
	CLR_BIT(TIMSK, OCIE2);

	SET_BIT(TIFR, TOV2);
	SET_BIT(TIFR, OCF2);

	TCNT2 = 0x00;
	OCR2  = 0x00;

	TCCR2 = (TCCR2 & 0xF8) | (TIM2_PRESCALER & 0x07);
}

void TIM2_voidDisable(void)
{
	TCCR2 &= 0xF8;
}

/* Normal Mode */

void TIM2_voidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK, TOIE2);
}

void TIM2_voidDisableOVInterrupt(void)
{
	CLR_BIT(TIMSK, TOIE2);
}

void TIM2_voidSetPreloadReg(u8 u8PreloadValue)
{
	TCNT2 = u8PreloadValue;
}

u8 TIM2_u8ReadTimerReg(void)
{
	return TCNT2;
}

void TIM2_voidOVSetCallBack(pf pvOVFunctionAddress)
{
	if (pvOVFunctionAddress != NULL)
	{
		TIM2_pvOVFCallBackFunc = pvOVFunctionAddress;
	}
}

/* CTC Mode */

void TIM2_voidEnableCOMPInterrupt(void)
{
	SET_BIT(TIMSK, OCIE2);
}

void TIM2_voidDisableCOMPInterrupt(void)
{
	CLR_BIT(TIMSK, OCIE2);
}

void TIM2_voidSetCompareReg(u8 u8CompareValue)
{
	OCR2 = u8CompareValue;
}

void TIM2_voidCOMPSetCallBack(pf pvCOMPFunctionAddress)
{
	if (pvCOMPFunctionAddress != NULL)
	{
		TIM2_pvCOMPCallBackFunc = pvCOMPFunctionAddress;
	}
}

/* Fast PWM Mode */

void TIM2_voidGeneratePWM(u8 u8DutyCycle)
{
	#if FAST_PWM_MODE == TIM2_PWM_NON_INVERTING
	OCR2 = (u8)(((u16)u8DutyCycle * 255) / 100);
	#elif FAST_PWM_MODE == TIM2_PWM_INVERTING
	OCR2 = 255 - (u8)(((u16)u8DutyCycle * 255) / 100);
	#endif
}

void TIM2_voidInitFastPWMWithInterrupt(void) {
    /* Set Timer2 to Fast PWM Mode */
    SET_BIT(TCCR2, WGM20);
    SET_BIT(TCCR2, WGM21);

    /* Hardware PWM output on PB3 (OC2 pin) for Pump control */
    CLR_BIT(TCCR2, COM20);
    SET_BIT(TCCR2, COM21);

    /* Clock Prescaler = 64 (F_CPU / 64) */
    SET_BIT(TCCR2, CS21);
    SET_BIT(TCCR2, CS20);
    CLR_BIT(TCCR2, CS22);

    /* Enable Overflow Interrupt for background timing */
    SET_BIT(TIMSK, TOIE2);

    overflow_counter = 0;
    seconds_counter = 0 ;
}

/* Initialize Timer2 in CTC mode to generate a precise 1ms tick,
 * which is accumulated into seconds_counter (accurate alternative
 * to the overflow-based approximation in TIM2_voidInitFastPWMWithInterrupt) */
void TIM2_voidInitCTC(void)
{
	/* Select CTC mode (WGM21 = 1, WGM20 = 0) */
	SET_BIT(TCCR2, WGM21);
	CLR_BIT(TCCR2, WGM20);

	/* Target value for 1ms tick (8MHz / 64 prescaler = 125kHz -> 249 counts = 2 ms) */
	OCR2 = 249;

	/* Enable Timer2 Compare Match interrupt */
	SET_BIT(TIMSK, OCIE2);

	/* Prescaler = 64 (CS22 = 1, CS21 = 0, CS20 = 0) */
	SET_BIT(TCCR2, CS22);
	CLR_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS20);

	millis_counter  = 0;
	seconds_counter = 0;
}

/* ISRs */
void __vector_4 (void) __attribute__ ((signal, used));
void __vector_4 (void)
{
	/* 1ms tick accounting (only meaningful while running in CTC mode,
	 * i.e. after TIM2_voidInitCTC() ) */
	millis_counter=millis_counter+2;
	if (millis_counter >= 1000)
	{
		seconds_counter++;
		millis_counter = 0;
	}

	if (TIM2_pvCOMPCallBackFunc != NULL)
	{
		TIM2_pvCOMPCallBackFunc();
	}
}

/* Timer2 Overflow ISR: Triggered every 2.048ms */
void __vector_5 (void) __attribute__ ((signal, used));
void __vector_5 (void)
{
	overflow_counter++;

    /* 488 overflows equal 1 second (488 * 2.048ms  1000ms) */
    if (overflow_counter >= 488)
    {

        seconds_counter++;      /* Increment second counter */
        overflow_counter = 0;   /* Reset tick counter */
    }
}
