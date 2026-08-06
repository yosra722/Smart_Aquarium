/*****************************************/
/******** Author: Yosra Madkour **********/
/******** Date  : 3/8/2026   *************/
/******** File  : Interface File *********/
/*****************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);

void ADC_voidADCEnable(void);
void ADC_voidADCDisable(void);

void ADC_voidSelectChannel(u8 u8channel);
void ADC_voidSelectRef(u8 u8ref);
void ADC_voidSelectClock(void);

u16 ADC_u16Read(void);

void ADC_voidStartConverstion(void);
void ADC_voidAutoTrigger(void);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidSetCallBack(void (*FunctionAddress)(void));

#endif
