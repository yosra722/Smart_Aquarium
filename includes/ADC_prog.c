/*****************************************/
/******** Author: Yosra Madkour **********/
/******** Date  : 3/8/2026   *************/
/******** File  : Program File ***********/
/*****************************************/

#include "Bit_Math.h"
#include "STD_Types.h"



#include "DIO_int.h"
#include "ADC_config.h"
#include "ADC_int.h"
#include "ADC_private.h"


void ADC_voidInit(void)
{
	ADC_voidADCDisable();
	CLR_BIT(ADCSRA,ADSC);
	CLR_BIT(ADCSRA,ADATE);
	CLR_BIT(ADCSRA,ADIE);
	SET_BIT(ADCSRA,ADIF);

	#if REG_ADJ == RIGHT_ADJUSTMEN
	CLR_BIT(ADMUX,ADLAR);
	#elif REG_ADJ == LEFT_ADJUSTMEN
	SET_BIT(ADMUX,ADLAR);
	#endif

	ADC_voidSelectChannel(ADC_CHANNEL);
	ADC_voidSelectClock();
	ADC_voidSelectRef(REF_SOURCE);

}




void ADC_voidADCEnable(void)
{
	SET_BIT(ADCSRA,ADEN);
}


void ADC_voidADCDisable(void){
	CLR_BIT(ADCSRA,ADEN);
}

void ADC_voidSelectChannel(u8 u8channel)
{
	ADMUX &= 0xE0;
	ADMUX |= u8channel;


}

void ADC_voidSelectRef(u8 u8ref)
{
	switch(u8ref){
	case AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	case AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	case Internal_REF:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}

}

void ADC_voidSelectClock(void)
{
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
}

u16 ADC_u16Read(void)
{
	u16 value ;

	while(!Get_Bit(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);

	u16 low_reg=ADCL;
	u16 high_reg = ADCH;

	#if REG_ADJ == LEFT_ADJUSTMEN
		value = (low_reg>>6)|(high_reg<<2);
	#elif REG_ADJ == RIGHT_ADJUSTMEN
		value = low_reg | (high_reg<<8);
	#endif

	return value;
}




void ADC_voidStartConverstion()
{
	SET_BIT(ADCSRA,ADSC);
}



void ADC_voidAutoTrigger(void)
{

	SET_BIT(ADCSRA,ADATE);
	SFIOR &=0x1F;
	SFIOR |=(FREE_RUNNING<<5);


}




void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_voidInterruptDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

pf ADC_CallBack;

void ADC_voidSetCallBack(pf FunctionAddress)
{
	ADC_CallBack = FunctionAddress;
}


void __vector_20(void)  __attribute__((signal, used));
void __vector_20(void)
{
	ADC_CallBack();
}

