#include "controller.h"
#include "../driver/pwm/timer0.h"
#include "../driver/trigger/timer1.h"
#include "../driver/adc/adc.h"
#include "../driver/mapping/mapping.h"
#include "../driver/uart/uart.h"
#include <util/atomic.h>
#include <stdio.h>

#ifdef DEBUG_UART
static volatile uint16_t sample_count = 0;
static volatile uint16_t adc_sample;
static volatile bool log_ready;
#endif

int controller_init(void)
{
	bool fail = timer0_init() || adc_init() || timer1_init();

	#ifdef DEBUG_UART
	fail = fail || uart_init();
	#endif

	if(fail) return 1;

	sei();
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
    // Start ADC Conversion
    adc_start();
}

ISR(ADC_vect)
{
	
    set_duty(adc_map(ADC));

	#ifdef DEBUG_UART
	sample_count++;
	if (sample_count == UART_LOG_DECIMATE) { adc_sample = ADC; log_ready = true; sample_count = 0; }
	#endif
}

#ifdef DEBUG_UART
void uart_logSample(void)
{
		uint16_t sample;

		ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		{  	
			if(log_ready)
			{
				sample = adc_sample;
				log_ready = false;
			}
			else return;
		}
		
		char buff[10];
		
		size_t i = snprintf(buff,sizeof(buff),"%u",sample) - 1;

		buff[++i] = ',';

		size_t temp = i; 
		
		i += snprintf(&buff[temp + 1],sizeof(buff) - (1 + temp),"%u",adc_map(sample)); 

		buff[++i] = '\r';

		buff[++i] = '\n';

		uart_putStream((uint8_t*)buff,i + 1);
}
#endif
