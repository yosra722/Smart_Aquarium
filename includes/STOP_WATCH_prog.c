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

 u32 OV_count = 0;

void STW_voidInitialization(void)
{

	TIM0_voidSetMode(TIM0_OVERFLOW);
	TIM0_voidOVSetCallBack(TIM0_voidCallback);
	//set TIM0  mode to ov
	//as a next step we will make same STW  but in more units
	TIM0_voidSetPerscaller( PERSCALLER_MODE );
	//clr reg
	TIM0_voidSetOVReg(0);
	//disable Tim0
	TIM0_voidDisableOVInterrupt();
	OV_count=0;

}
void STW_voidStart(void) //start count
{
	TIM0_voidDisableOVInterrupt();
	TIM0_voidSetOVReg(0);
	OV_count=0;
	TIM0_voidEnableOVInterrupt();
}

/************************ Microsecond ***************************/
#define STW_CALIBRATION_OFFSET_US   285
u16 STW_u16StopANDWatch_usec(void)
{
    u16 TIM0_u16CurrentRegValue;
    u16 Local_u16OVCount;
    u16 Local_u16Result;

    TIM0_voidDisableOVInterrupt();
    //GIE_voidDisable();
    TIM0_u16CurrentRegValue = (u16)TIM0_u8ReadOVReg();
    Local_u16OVCount = (u16)OV_count;
    //GIE_voidEnable();



    Local_u16Result = TIM0_u16CurrentRegValue + (256 * Local_u16OVCount);

    TIM0_voidSetOVReg(0);
    OV_count = 0;


    if (Local_u16Result > STW_CALIBRATION_OFFSET_US)
        Local_u16Result -= STW_CALIBRATION_OFFSET_US;
    else
        Local_u16Result = 0;

    return Local_u16Result;
}

static void TIM0_voidCallback(void)
{
	OV_count++;
}


