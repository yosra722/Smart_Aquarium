/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 02/07/2026   ************/
/************** File  : Interface File  *********/
/********* Last Update: 02/08/2026   ************/
/************************************************/

#define ADC_INT_H
#ifdef  ADC_INT_H
//set input pin in DIO

void ADC_voidInitialization (void);

void ADC_voidEnable(void);
void ADC_voidDisable(void);

void ADC_voidStartConversion(void); //Bit 6 – ADSC: ADC Start Conversion at ADCSRA & enable ADC
void ADC_voidAutoTrigger(void); //Bit 6 at ADCSRA //Set auto Trigger Enable //set the source of auto Trigger

void ADC_voidSetTriggerSourse(u8 u8TriggerSourseID);

void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);

u16 ADC_u16Read(void);


#define LEFT_ADJUSTMEN   1
#define RIGHT_ADJUSTMEN  0


#endif
