#ifndef ctrl_h
#define ctrl_h
#include <stdbool.h>
#include <avr/interrupt.h>

int controller_init(void);
void uart_logSample(void);
#endif
