#include "STD_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "GIE_int.h"
#include "TIM0_int.h"
#include "STOP_WATCH_int.h"
#include "LCD_int.h"
#include <util/delay.h>

#define F_CPU 8000000UL

void LCD_voidPrintNumber(u32 Copy_u32Number);

int main(void)
{

    DIO_voidSetPortDirection(PORTAID, OUTPUT);
    DIO_voidSetPortValue(PORTAID, 0x00);

    DIO_VoidSetPinDirection(PORTBID, PIN0, OUTPUT); // RS
    DIO_VoidSetPinDirection(PORTBID, PIN1, OUTPUT); // RW
    DIO_VoidSetPinDirection(PORTBID, PIN2, OUTPUT); // E


    TIM0_voidInitialization();
    GIE_voidEnable( );

    LCD_voidIntialization();
    STW_voidInitialization();

    LCD_voidWriteString((u8*)" STW TEST START", 0);
    u16 delay = 50 ;

    while (1)
    {
        LCD_voidSendCommand(0x01); // Clear Display
        _delay_ms(2);


        STW_voidStart();
        _delay_us(delay);
        u16 Local_u16MeasuredUs = STW_u16StopANDWatch_usec();

        LCD_voidPrintNumber(delay);
        LCD_voidSendData(':');
        LCD_voidPrintNumber((u32)Local_u16MeasuredUs);
        LCD_voidSendData('u');
        LCD_voidSendData('s');
        delay= delay *2;
        _delay_ms(1500);
    }

    return 0;
}
void LCD_voidPrintNumber(u32 Copy_u32Number)
{
    u8 Local_u8Buffer[100];
    s8 Local_s8Index = 0;

    if (Copy_u32Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }

    while (Copy_u32Number > 0)
    {
        Local_u8Buffer[Local_s8Index] = (Copy_u32Number % 10) + '0';
        Copy_u32Number /= 10;
        Local_s8Index++;
    }

    while (Local_s8Index > 0)
    {
        Local_s8Index--;
        LCD_voidSendData(Local_u8Buffer[Local_s8Index]);
    }
}
