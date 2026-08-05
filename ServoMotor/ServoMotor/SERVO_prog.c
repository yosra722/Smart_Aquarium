#include "STD_TYPES.H"
#include "BIT_MATH.H"
#include "DIO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

void SERVO_voidInit(void){
    #if SERVO_CHANNEL == SERVO_CHANNEL_A
    DIO_voidSetPinDirection(PORT_D, PIN5, OUTPUT);
    SET_BIT(TCCR1A_REG,COM1A1_BIT);

    #elif SERVO_CHANNEL == SERVO_CHANNEL_B
    DIO_voidSetPinDirection(PORT_D, PIN4, OUTPUT);
    SET_BIT(TCCR1A_REG,COM1B1_BIT);
    #endif
    
    /*0111 --> FAST PWM MODE 14*/
    CLR_BIT(TCCR1A_REG,WGM10_BIT);
    SET_BIT(TCCR1A_REG,WGM11_BIT);
    SET_BIT(TCCR1B_REG,WGM12_BIT);
    SET_BIT(TCCR1B_REG,WGM13_BIT);
    
    /*010 ---> PRESCALER = 8*/
    CLR_BIT(TCCR1B_REG, CS10_BIT);
    SET_BIT(TCCR1B_REG, CS11_BIT);
    CLR_BIT(TCCR1B_REG, CS12_BIT);

    ICR1_REG = SERVO_TIMER1_TOP_VALUE;
}

void Servo_voidSetAngle(u8 u8Angle){
    if (u8Angle > SERVO_MAX_PULSE_TICKS){
        u8Angle = SERVO_MAX_PULSE_TICKS;
    }
//      PulseWidth =        (1000          +        ((angle*                  (2000-1000))                    /    180))
    u16 PulseWidth = SERVO_MIN_PULSE_TICKS + (((u32)u8Angle * (SERVO_MAX_PULSE_TICKS - SERVO_MIN_PULSE_TICKS))/SERVO_MAX_ANGLE);

    #if SERVO_CHANNEL == SERVO_CHANNEL_A
        OCR1A_REG = PulseWidth;

        #elif SERVO_CHANNEL == SERVO_CHANNEL_B
        OCR1B_REG = PulseWidth;
    #endif
}