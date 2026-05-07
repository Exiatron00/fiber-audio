#include "uart.h"

#define UBRR_SET ((((F_CPU) + (8UL * UART_BAUD)) / (16UL * UART_BAUD)) - 1)

//sets async uart normal speed 8-N-1
int uart_init(void)
{
	//set UART0 TX as output
	DDRD |= (1 << PD1);	

	//set baud rate
	UBRR0L = UBRR_SET; //no need to set high bits
	
	//enable transmitter
	UCSR0B = (1 << TXEN0);

	//set frame format 8-N-1 (only '8 data bits' needs to be explicitly set here)
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

	return 0;
}


void uart_putByte(uint8_t byte)
{
	//wait for uart transmit buffer to clear then place 1 byte - blocking
	while (!( UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

void uart_putStream(const uint8_t* buffer, uint16_t len)
{
	//iterate over input data buffer & call putByte on each byte of input buffer
	for(uint16_t x = 0; x < len; x ++) { uart_putByte(*(buffer + x)); }
}
