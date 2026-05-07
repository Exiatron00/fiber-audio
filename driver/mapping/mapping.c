#include "mapping.h"

static const uint8_t adc_to_pwm[MAX + 1] PROGMEM = {
    //populate values using preprocessor
	#include "adc_lut.inc"
};

uint8_t adc_map(uint16_t adc)
{
    // clamp to max
    if (adc > MAX) {
        adc = MAX;
    }

    // read one byte from PROGMEM table
    return pgm_read_byte(&adc_to_pwm[adc]);
}
