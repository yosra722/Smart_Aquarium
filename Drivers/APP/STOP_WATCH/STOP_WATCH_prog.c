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

static u16 OV_count = 0;

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


	
}
void STW_voidStart(void) //start count
{
	TIM0_voidSetOVReg(0);
	GIE_voidEnable();
	
	TIM0_voidEnableOVInterrupt();
}  

u16 STW_u16StopANDWatch_usec(void)  // Stop counting and init STW IN microsecond
{
	u16 TIM0_u16CurrentRegValue ;
	u16 u16TimeInMicrosecound ;

	TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();
	TIM0_voidDisableOVInterrupt();
	TIM0_voidSetOVReg(0);
	
	u16TimeInMicrosecound = TIM0_u16ConvertFromCountstoMicrosecound(OV_count , TIM0_u16CurrentRegValue);

	OV_count = 0 ;

	return u16TimeInMicrosecound ;


}

u16  STW_u16Watch__usec(void)         //counting will continue
{
	    u16 TIM0_u16CurrentRegValue ;
		u16 u16TimeInMicrosecound ;

		TIM0_u16CurrentRegValue = TIM0_u8ReadOVReg();

		u16TimeInMicrosecound = TIM0_u16ConvertFromCountstoMicrosecound(OV_count , TIM0_u16CurrentRegValue);

		return u16TimeInMicrosecound ;
}


static void TIM0_voidCallback(void)
{

	OV_count++;

}
static u16 TIM0_u16ConvertFromCountstoMicrosecound(u16 OV_counts , u16 u16CurrentRegValue )
{
	u16 TotalCount = (OV_counts * 255 ) + u16CurrentRegValue ;

	u16 TotalTime_nanosec  = TICK_TIME_nSEC * TotalCount ;

	return  TotalTime_nanosec /1000 ;

}
