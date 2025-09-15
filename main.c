#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "LCD.h"

/*
 Main application
*/
void main(void)
{
    int   j;
    int   a = 2025;
    float c = 0.45;

    // initialize the device
    SYSTEM_Initialize();

    Lcd_Init();
    Lcd_Clear();
    __delay_ms(2);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("PIC16f1718 "); //write string
    __delay_ms(500);
    Lcd_Write_Integer(a); //write integer
    for (j=0; j<15; j++)
    {
      __delay_ms(500);
      Lcd_Shift_Right();
    }
    Lcd_Clear();
    __delay_ms(2);
    Lcd_Write_Float(c); //write float
    __delay_ms(1000);

    // ADD NEW CODE HERE
    Lcd_Clear();
    __delay_ms(2);

    // 0x83 (endereço DDRAM posição 4)
    EN = 0;
    RS = 0; // 0: Escrita de instruções
    D7 = 1; D6 = 0; D5 = 0; D4 = 0; // nibble mais significativo
    EN = 1;
    __delay_us(20);
    EN = 0;
    D7 = 0; D6 = 0; D5 = 1; D4 = 1; // nibble menos significativo
    EN = 1;
    __delay_us(20);
    EN = 0;
    __delay_ms(2);

    // 0x31 (caractere '1')
    RS = 1; // 1: Escrita de dados
    D7 = 0; D6 = 0; D5 = 1; D4 = 1; // nibble mais significativo
    EN = 1;
    __delay_us(20);
    EN = 0;
    D7 = 0; D6 = 0; D5 = 0; D4 = 1; // nibble menos significativo
    EN = 1;
    __delay_us(20);
    EN = 0;

    while (1)
    {
      if (Switch_GetValue() == 0)
      {
        LED_SetHigh();
      }
      else
      {
        LED_SetLow();
      }
    }
}
/*
 End of File
*/
