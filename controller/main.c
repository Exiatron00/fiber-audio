#include "controller.h"
#include <avr/sleep.h>


int main(void)
{
	//intitialise peripherals
	controller_init();
	
	//set sleep mode
	set_sleep_mode(SLEEP_MODE_IDLE);

	while(1)
	{
		#ifndef DEBUG_UART
		//go to sleep... zzzz    
		sleep_mode();   
		#endif
		
		#ifdef DEBUG_UART
		uart_logSample();
		#endif
	}
	
}