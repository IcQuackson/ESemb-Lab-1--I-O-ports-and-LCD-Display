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
