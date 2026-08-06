#include "Bit_Math.h"
#include "STD_Types.h"


#include "GIE_int.h"
#include "GIE_config.h"
#include "GIE_private.h"

void GIE_voidEnable(void)
{
	//SREG--> bit 7 general interrupt enable
	/**should i make clear to all interrupt flags here ?*/
	SET_BIT(SREG , 7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG , 7);
}
