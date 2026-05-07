#STATIC PARAMETERS
MCU = atmega164p
F_CPU = 20000000UL
CC = avr-gcc
HOSTCC = gcc
OBJCPY = avr-objcopy
BAUD = 115200
PORT = /dev/serial/by-id/usb-1a86_USB_Serial-if00-port0

#CONFIGURABLE PARAMETERS
decimate ?= 40

#OBJS PATHS
OBJS = controller/controller.o \
       controller/main.o \
       driver/adc/adc.o \
       driver/mapping/mapping.o \
       driver/pwm/timer0.o \
       driver/trigger/timer1.o

#GCC FLAGS

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra 

#BUILD TARGETS
all: main.hex
main.hex: main.elf
	$(OBJCPY) -O ihex -R .eeprom $< $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

tools/gen_lut: tools/gen_lut.c
	$(HOSTCC) -o $@ $<

driver/mapping/adc_lut.inc: tools/gen_lut
	./tools/gen_lut > $@

driver/mapping/mapping.o: driver/mapping/adc_lut.inc

flashISP: main.hex 
	sudo avrdude -c usbasp -p m164p -U flash:w:$<

flash: main.hex
	sudo avrdude -c urclock -p m164p -P $(PORT) -b $(BAUD) -U flash:w:$<


#DEBUG TARGETS
debug: driver/uart/uart.o
debug: CFLAGS += -DDEBUG_UART -DUART_LOG_DECIMATE=$(decimate) -DUART_BAUD=$(BAUD) 
debug: OBJS += driver/uart/uart.o
debug: main.hex



clean:
	rm -f *.elf *.hex $(OBJS) driver/mapping/adc_lut.inc tools/gen_lut driver/uart/uart.o

.PHONY: all clean flash flashISP
