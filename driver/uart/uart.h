#ifndef UART_H
#define UART_H
#include <avr/io.h>
#include<stdint.h>
int uart_init(void);
void uart_putByte(uint8_t b);
void uart_putStream(const uint8_t *buf, uint16_t len);
#endif
