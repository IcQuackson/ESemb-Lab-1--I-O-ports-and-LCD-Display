# Lab 1 – I/O Ports & LCD Display

📚 Course: Embedded Systems Electronics (ESE-2526)
🔧 Platform: PIC16F1718 + MPLAB X + MCC + PICkit 3

---

## Overview

This lab introduces:

* Configuring microcontroller I/O ports (input + output).
* Driving an external LCD display via parallel communication.
* Using MPLAB X IDE, MCC, and debugging with simulator + hardware.

---

## Circuit

![Circuit](circuit.png)
![Group Data](group_data.png)

---

## Simulation Analysis

### Registers at Init

```c
// LATx
LATA = 0x00; LATB = 0x00; LATC = 0x00;
// TRISx
TRISA = 0xFD; TRISB = 0xC0; TRISC = 0xFF; TRISE = 0x08;
// ANSELx
ANSELA = 0x3A; ANSELB = 0x00; ANSELC = 0xFC;
```

### Macros

* **Switch\_GetValue()** → reads RA0 (ON/OFF)
* **LED\_SetHigh()** → sets RA1 = 1 (LED ON)
* **LED\_SetLow()** → sets RA1 = 0 (LED OFF)

### SFR Addresses

* `TRISA`: 0x08C
* `PORTA`: 0x00C
* `LATA`: 0x10C

---

## Debug Results

* Breakpoints: `LED_SetHigh` / `LED_SetLow`
* With switch **High**, LED is **OFF**

| Register | Addr  | Value | Notes                |
| -------- | ----- | ----- | -------------------- |
| PORTA    | 0x0C  | 0x01  | RA0=1 (switch High)  |
| TRISA    | 0x8C  | 0xFD  | unchanged            |
| LATA     | 0x10C | 0x00  | latch, not pin state |

💡 **Reminder:** LATA shows last written latch, not real pin state.

---

## ANSELA

`00111000` → RA0/RA1 digital, rest analog.

## OSCCON

`01101000` → IRCF = `1101` → 4 MHz internal oscillator.

---

## Expected Behavior

* Switch Low → LED ON.
* Switch High → LED OFF.
* LCD displays group number `n` at position `n+3`.

---
