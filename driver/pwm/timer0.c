#include "timer0.h"


int timer0_init(void)
{
	//set OC0A as output for PWM
	DDRB |= (1 << PB3);

	//Fast 8-bit PWM - clear OC0A on compare match
	TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);

	//no prescaler
	TCCR0B = (1 << CS00);	
	return 0;

}

void set_duty(uint8_t pwm)
{
	//set new duty cycle
	OCR0A = pwm;
}
