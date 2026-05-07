#include <stdio.h>
#include <stdint.h>

#define MAX 1000

int main(void)
{
	for(uint16_t adc =  0; adc <= MAX; ++adc)
	{
		uint8_t pwm = adc * 255/MAX;
		printf("%u",pwm);
		if(adc != MAX) printf(",");	
	}	
	return 0;
}

