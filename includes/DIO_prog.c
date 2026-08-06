/************************************************/
/********* Author: Khadija Naji *****************/
/********* Date  : 29/07/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/
#include "Bit_Math.h"
#include "STD_Types.h"

#include "DIO_int.h"

#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidInitialization(void)
{
	DDRA = DIO_PORTA_DIRECTIONS ;
	DDRB = DIO_PORTB_DIRECTIONS ;
	DDRC = DIO_PORTC_DIRECTIONS ;
	DDRD = DIO_PORTD_DIRECTIONS ;
}
/** mode set*/
void DIO_voidSetPinDirection (u8 PortID, u8 PinID, u8 Direction)
{
	if(PinID <10 && PortID < 4)
	{
	if (Direction == OUTPUT)
    {
        switch (PortID)
        {
             case PORTAID: SET_BIT(DDRA ,PinID); break;
             case PORTBID: SET_BIT(DDRB ,PinID); break;
             case PORTCID: SET_BIT(DDRC ,PinID); break;
             case PORTDID: SET_BIT(DDRD ,PinID); break;
             
        }
    } else if (Direction == INPUT)
    {
        switch (PortID)
        {
             case PORTAID: CLR_BIT(DDRA ,PinID); break;
             case PORTBID: CLR_BIT(DDRB ,PinID); break;
             case PORTCID: CLR_BIT(DDRC ,PinID); break;
             case PORTDID: CLR_BIT(DDRD ,PinID); break;
        }
    }else
    {
      //NO CODE  
    }	
	}else
	{
		//NO CODE
	}
		
    
}

/** output mode*/
void DIO_voidSetPinValue     (u8 PortID , u8 PinID , u8 Value)
{
	if(PinID <10 && PortID < 4)
	{
	if(Value == HIGH)
	{
		switch(PortID)
		{
			 case PORTAID: SET_BIT(PORTA ,PinID); break;
             case PORTBID: SET_BIT(PORTB ,PinID); break;
             case PORTCID: SET_BIT(PORTC ,PinID); break;
             case PORTDID: SET_BIT(PORTD ,PinID); break;
		}	
	}else if (Value == LOW)
	{
        switch (PortID)
        {
             case PORTAID: CLR_BIT(PORTA ,PinID); break;
             case PORTBID: CLR_BIT(PORTB ,PinID); break;
             case PORTCID: CLR_BIT(PORTC ,PinID); break;
             case PORTDID: CLR_BIT(PORTD ,PinID); break;
        }
	}else
	{
		//NO CODE
	}
	}else
	{
		//NO CODE
	}
	
}
/** output mode*/
void DIO_voidTogglePin(u8 PortID, u8 PinID)
{
	if(PinID <10 && PortID < 4)
	{
		switch(PortID)
		{
			 case PORTAID: TOG_BIT(PORTA ,PinID); break;
             case PORTBID: TOG_BIT(PORTB ,PinID); break;
             case PORTCID: TOG_BIT(PORTC ,PinID); break;
             case PORTDID: TOG_BIT(PORTD ,PinID); break;
		}	
	}else
	{
		//NO CODE
	}
	
}
/** output - input*/
void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
	if( PortID < 4)
	{
    
        switch (PortID)
        {
             case PORTAID: SET_BYTE(DDRA ,Direction); break;
             case PORTBID: SET_BYTE(DDRB ,Direction); break;
             case PORTCID: SET_BYTE(DDRC ,Direction); break;
             case PORTDID: SET_BYTE(DDRD ,Direction); break;
             
        }
	}else
	{
		//NO CODE
	}
}

/** Input Mode*/
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID)
{
	if( PortID < 4 && PinID < 10 )
	{
        switch (PortID)
        {
             case PORTAID: return Get_Bit(PINA ,PinID);
             case PORTBID: return Get_Bit(PINB ,PinID);
             case PORTCID: return Get_Bit(PINC ,PinID);
             case PORTDID: return Get_Bit(PIND ,PinID);
             
        }
	}else
	{
		//NO CODE
	}
	

}
/** High - Low*/
void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
	if(PortID < 4)
	{
		switch(PortID)
		{
			 case PORTAID: SET_BYTE(PORTA ,Value); break;
             case PORTBID: SET_BYTE(PORTB ,Value); break;
             case PORTCID: SET_BYTE(PORTC ,Value); break;
             case PORTDID: SET_BYTE(PORTD ,Value); break;
		}	
	}else
	{
		//NO CODE
	}
	
	
}

