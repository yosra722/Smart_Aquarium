/************************************************/
/************** Author: Khadija Naji ************/
/************** Date  : 03/07/2026   ************/
/************** File  : Interface File  *********/
/********* Last Update: 03/08/2026   ************/
/************************************************/

#define TIM0_INT_H
#ifdef  TIM0_INT_H
//set input pin in DIO

void TIM0_voidInitialization(void);
void TIM0_voidSetPerscaller(u8 u8TIM0Prescaller);
/*****************NORMAL Mode*****************/
// to Enable the interrupt of Over flow
void TIM0_voidEnableOVInterrupt(void);

// to Disable the interrupt of Over flow
void TIM0_voidDisableOVInterrupt(void);

//to Set the overflow Register(TCNT0) with specificValue
void TIM0_voidSetOVReg(u8 u8OVRegValue);

//to read the overflow Register(TCNT0)
u8 TIM0_u8ReadOVReg(void);

void TIM0_voidOVSetCallBack(pf OVFunctionAddress);
/********************CTC Mode*****************/
// to Enable the interrupt of CTC
void TIM0_voidEnableCTCInterrupt(void);

// to Disable the interrupt of CTC
void TIM0_voidDisableCTCInterrupt(void);

//to Set the CTC Register(OCR0) with specificValue
void TIM0_voidSetCTCReg(u8 u8CTCRegValue);

//to read the CTC Register(OCR0)
u8 TIM0_u8ReadCTCCTCReg(void);

void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress);
#endif
