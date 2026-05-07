# Fiber Audio TX

Firmware for a custom fiber-optic audio transmitter based on AVR microcontrollers.

<img width="3072" height="3074" alt="PXL_20260411_141839496" src="https://github.com/user-attachments/assets/e473ced7-9090-4f83-a691-1929b68d33cf" />

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

## Build Instructions - normal

1.) `make clean` - cleanup  

2.) `make all` - build hex binary  

3.) `make flash` - flash via UART  **OR** `make flashISP` - flash via ISP  


---
## Build Instructions - normal (logging ADC & PWM over USB)

1.) `make clean` - cleanup  

2.) `make debug` - build hex binary  **OR**  optionally `make debug decimate = d` to specify decimation factor (default = 40)

3.) `make flash` - flash via UART  **OR** `make flashISP` - flash via ISP  


## Supported MCUs

- ATmega164P/V
- ATmega324P/V
- ATmega644P/V

> **Note:** `Makefile` must be changed accordingly for the selected MCU.
