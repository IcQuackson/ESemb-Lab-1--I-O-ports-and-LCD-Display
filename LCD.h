
// Modified in 15/9/2022
// Added include <stdio.h> to use sprintf 

/* 
 * File:   LCD.h
 * Author: JP
 * Comments:
 * Revision history: 
 */

/* Program Description: This program header provides routines
for controlling
* a STD HITACHI HD44780 and compatible LCDs
*
* Hardware Description:
*
* RS ---> RB0
* R/W ---> GND
* EN ---> Rb1
* D4 ---> RB5
* D5 ---> RB2
* D6 ---> RB4
* D7 ---> RB3
*
*/

/**************************************************************
*Includes and defines
**************************************************************/
// STD XC8 include
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RS RB0 //Register Select (Character or Instruction)
#define EN RB1 //LCD Clock Enable PIN, Falling Edge Triggered
// 4 bit operation
#define D4 RB5 //Bit 4
#define D5 RB2 //Bit 5
#define D6 RB4 //Bit 6
#define D7 RB3 //Bit 7
// function prototypes
void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear(void);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(const char *a);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);
void Lcd_Write_Integer(int v);
void Lcd_Write_Float(float f);