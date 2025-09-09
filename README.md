## Simulation results analysis

```
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x08;
    TRISA = 0xFB;
    TRISB = 0xC0;
    TRISC = 0xFF;
```

### Macros meaning

1. Check if switch is **ON** or **OFF**:

    ```c
    #define Switch_GetValue()           PORTAbits.RA1
    ```

2. Turn **ON** the LED:

    ```c
    #define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
    ```

3. Turn **OFF** the LED:

    ```c
    #define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
    ```

### SFR addresses

- TRISA: ```08C```
- PORTA: ```00C```
- LATA: ```10C```


### Experience

- After running debugger with breakpoints on LED_SetHigh and LED_SetLow with Stimulus fired to stop at Low.

#### SFR values
- PORTA: ```0x02```		changed from ```0x00```
- TRISA: ```0xFB``` 	unchanged
- LATA: ```0x00```		unchanged

| Register (Addr) | Bit7  | Bit6  | Bit5  | Bit4  | Bit3  | Bit2  | Bit1  | Bit0  |
| --------------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| PORTA (0x0C)    | RA7=0 | RA6=0 | RA5=0 | RA4=0 | RA3=0 | RA2=0 | RA1=1 | RA0=0 |


According to the program:
- when the switch is Low, turn **ON** the LED.
- when the switch is High, turn **OFF** the LED.

Since the switch is High for this experience then the LED is **OFF** and R1 is set to '1' and **PORTA** will show ```0x02```

TRISA is correctly unchanged since we didn't change the type of pin.

#### Why is LATA still '0' and not '1'?

Reading LATA tells you the last value written to the latch, not the actual pin state.

#### ANSELA

ANSELA = '00111001'

ANSELA1 = 0
ANSELA2 = 0

ANSELA has 6 bits used in an 8 bit register so:
-  The 2 MSB will be set to 0
- Our ANSELA1 and 2 are set to '0' (digital)
- The rest is set to '1' (analog).

*(See page 126 from provided Datasheet-PIC16F1718)*

#### OSCCON

OSCCON = '01101000'

IRCF<3:0> = '1101'

According to the *Datasheet-PIC16F1718*:
- '1101' means the Internal Oscillator Frequency is at 4 MHz HF, as expected.
