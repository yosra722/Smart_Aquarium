/*****************************************/
/******** Author: Yosra Madkour **********/
/******** Date  : 3/8/2026   *************/
/******** File  : Private File ***********/
/*****************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H



/*ADMUX*/
#define ADMUX					*((volatile u8*)0x27)
#define REFS1					7
#define REFS0					6
#define ADLAR 					5
#define ADC_C4					4
#define ADC_C3					3
#define ADC_C2					2
#define ADC_C1					1
#define ADC_C0					0



/*channels*/
#define ADC0    				0
#define ADC1    				1
#define ADC2    				2
#define ADC3    				3
#define ADC4    				4
#define ADC5    				5
#define ADC6    				6
#define ADC7    				7

/*ADLAR*/
#define LEFT_ADJUSTMEN 			1
#define RIGHT_ADJUSTMEN 		0


/*ADCSRA*/
#define ADCSRA					*((volatile u8*)0x26)
#define ADEN					7
#define ADSC					6
#define ADATE 					5
#define ADIF					4
#define ADIE					3
#define ADPS2					2
#define ADPS1					1
#define ADPS0					0


/*SFIOR*/
#define SFIOR					*((volatile u8*)0x50)
#define ADTS2					7
#define ADTS1					6
#define ADTS0					5
#define ACME					3
#define PUD						2
#define PSR2					1
#define PSR10					0


/*ADC*/
#define ADCL					*((volatile u8*)0x24)
#define ADCH					*((volatile u8*)0x25)



/*reference*/
#define AREF					1
#define AVCC					2
#define Internal_REF 			3

/*AUTO_TIGGER_MODES*/
#define FREE_RUNNING			0
#define ANAOLG_COM				1
#define EX_INT					2
#define TIMER0_COM_MATCH		3
#define TIMER0_OVERFLOW			4
#define TIMER1_COM_MATCH		5
#define TIMER1_OVERFLOW			6
#define TIMER1_CAP_EVENT		7



#endif

//ayatabs
