

#define ISR_FUNCTIINS_H
#ifdef  ISR_FUNCTIINS_H

void US_callBack(void );  //ultrasonic --> PUMP 

void LM32_callBack(void );  //temp. --> HEATER

void TIM0_callBack(void );  //time --> OV COUNT --> TIME COUNT --> DAY COUNTER --> SERVO

void RESET_callback(void);  // clear days count , OFF pump , OFF Heater  , 


#endif