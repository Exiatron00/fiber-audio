#include "adc.h"


int adc_init(void)
{

	//disable input buffer on ADC0
	DIDR0 |= (1 << ADC0D);

	//select ADC0 and Set voltage reference to AVCC
	ADMUX = (1 << REFS0);

	//Enable interrupts and set Prescale 32
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS0);
	
	return 0;

}

void adc_start(void)
{
	//start an adc conversion
	ADCSRA |= (1 << ADSC);
}


