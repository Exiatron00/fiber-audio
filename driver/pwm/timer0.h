#ifndef timer0_h
#define timer0_h
#include <avr/io.h> 
#include <stdint.h>

int timer0_init(void);
void set_duty(uint8_t pwm);
#endif
