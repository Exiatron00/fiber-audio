# fiber-audio-tx

Firmware for the fiber-optic audio transmitter based on AVR microcontrollers.

---

## Dependencies

### Required
- `gcc`
- `avr-gcc`
- `avr-libc`
- `avrdude`
- `make`

### Install on Debian/Ubuntu

```bash
sudo apt install gcc-avr binutils-avr avr-libc avrdude build-essential
```

Or use whatever AVR-compatible toolchain you want.

---

## Build Instructions

1.) `make clean` - cleanup  

2.) `make all` - build hex binary  

3.) `make flash` - flash via UART  **OR** `make flashISP` - flash via ISP  

---

## Supported MCUs

- ATmega164P/V
- ATmega324P/V
- ATmega644P/V

> **Note:** `Makefile` must be changed accordingly for the selected MCU.
