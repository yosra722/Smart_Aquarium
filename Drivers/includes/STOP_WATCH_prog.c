/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 06/08/2026   ************/
/************** File  : Program File  ***********/
/********* Last Update: 06/08/2026   ************/
/************************************************/

#include "Bit_Math.h"
#include "STD_Types.h"

#include "TIM0_int.h"
#include "GIE_int.h"


#include "STOP_WATCH_int.h"
#include "STOP_WATCH_config.h"
#include "STOP_WATCH_private.h"


static u32 OV_count = 0;

void STW_voidInitialization(void)
{
	//set TIM0  mode to ov
	TIM0_voidOVSetCallBack( TIM0_voidCallback );
	//as a next step we will make same STW  but in more units
	TIM0_voidSetPerscaller( PERSCALLER_MODE );
	//clr reg
	TIM0_voidSetOVReg(0);
	//disable Tim0
	TIM0_voidDisableOVInterrupt();
	TIM0_voidSetMode(TIM0_OVERFLOW);

}
void STW_voidStart(void) //start count
{
	OV_count = 0;
	TIM0_voidSetOVReg(0);
	GIE_voidEnable();

	TIM0_voidEnableOVInterrupt();
}

/************************ Microsecond ***************************/
u16 STW_u16StopANDWatch_usec(void)  // Stop counting and init STW IN microsecond
{
	u16 TIM0_u16CurrentRegValue ;
	u32 u32TimeInMicrosecound ;

	TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();
	TIM0_voidDisableOVInterrupt();
	TIM0_voidSetOVReg(0);

	u32TimeInMicrosecound = TIM0_u32ConvertFromCountstoMicrosecound((u16)OV_count , TIM0_u16CurrentRegValue);

	OV_count = 0 ;

	return (u16)u32TimeInMicrosecound ;
}

u16  STW_u16Watch__usec(void)         //counting will continue
{
	u16 TIM0_u16CurrentRegValue ;
	u32 u32TimeInMicrosecound ;

	TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();

	u32TimeInMicrosecound = TIM0_u32ConvertFromCountstoMicrosecound((u16)OV_count , TIM0_u16CurrentRegValue);

	return (u16)u32TimeInMicrosecound ;
}

/************************ Millisecond ***************************/

u32 STW_u32StopANDWatch_msec(void)
{
	u16 TIM0_u16CurrentRegValue ;
	u32 u32TimeInMicrosecound ;

	TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();
	TIM0_voidDisableOVInterrupt();
	TIM0_voidSetOVReg(0);

	u32TimeInMicrosecound = TIM0_u32ConvertFromCountstoMicrosecound((u16)OV_count , TIM0_u16CurrentRegValue);

	OV_count = 0 ;

	return u32TimeInMicrosecound / 1000UL ;
}

u32 STW_u32Watch_msec(void)
{
	u16 TIM0_u16CurrentRegValue ;
	u32 u32TimeInMicrosecound ;

	TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();

	u32TimeInMicrosecound = TIM0_u32ConvertFromCountstoMicrosecound((u16)OV_count , TIM0_u16CurrentRegValue);

	return u32TimeInMicrosecound / 1000UL ;
}

/************************ Second ***************************/

u16 STW_u16StopANDWatch_sec(void)
{
	return (u16)(STW_u32StopANDWatch_msec() / 1000UL);
}

u16 STW_u16Watch_sec(void)
{
	return (u16)(STW_u32Watch_msec() / 1000UL);
}


static void TIM0_voidCallback(void)
{
	OV_count++;
}

static u32 TIM0_u32ConvertFromCountstoMicrosecound(u16 OV_counts , u16 u16CurrentRegValue )
{
	u32 TotalCount = ((u32)OV_counts * 256UL ) + u16CurrentRegValue ;

	u32 TotalTime_nanosec  = (u32)TICK_TIME_nSEC * TotalCount ;

	return  TotalTime_nanosec / 1000UL ;
}
