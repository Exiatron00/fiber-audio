#include "timer1.h"
#define TOP 499
int timer1_init(void)
{
	//set TOP value
	OCR1A = TOP;

	//CTC - TOP = OCR1A no prescaler
	TCCR1B = (1 << WGM12) | (1<< CS10);

	//Enable interrupt on compare match
	TIMSK1 |= (1 << OCIE1A);

	return 0;
}
