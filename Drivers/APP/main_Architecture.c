

int main() 
{
	
	while(1)
	{
	/************************** Ultrasonic / pump  ***************************/
	// RANGE WATER -->< FULL ---> NORMAL RANGE --> DANGER=ON PUMP
	// UL_VALUR = READ UL 
	// if(UL_VALUR <=  DANGER)                         //FLAG IS O/P Connected with EXT0 
	//     {UL_FLAG = 1;}                              //EXT0 MODE ANY Changes mode ISR FOR EXT0 SHOULD TAGGLE PUMP STATE
    // else if (UL_VALUR >= FULL )
	//      {UL_FLAG = 0;}
	
	/************************** Temp / Heater  *******************************/
	// RANGE TEMP -->< FULL ---> NORMAL RANGE --> DANGER=ON HEATER
	// LM32_VALUR = READ UL 
	// if(LM32_VALUR <=  DANGER)                         //FLAG IS O/P Connected with EXT1 
	//     {LM32_FLAG = 1;}                              //EXT1 MODE ANY Changes mode ISR FOR EXT1 SHOULD TAGGLE PUMP STATE
    // else if (LM32_VALUR >= FULL )
	//      {LM32_FLAG = 0;}

	/************************** Timer / Servo   ******************************/
	}
	return 0 ; 
}