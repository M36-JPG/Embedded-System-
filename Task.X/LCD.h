#ifndef LCD_H
#define LCD_H

#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include "GPIO_INTERFACING.h"
#include <stdio.h>

//PORTs and PINs
#define LCD_DATA_PORT    GPIO_PORTB
#define LCD_CONTROL_PORT    GPIO_PORTC

#define LCD_RS_PIN GPIO_PIN0
#define LCD_RW_PIN GPIO_PIN1
#define LCD_E_PIN GPIO_PIN2

//COMMANDs
#define LCD_CLR_DIS 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE 0x06
#define LCD_DIS_ON 0x0C // display on , cursor off
#define LCD_Dis_ON 0x0E // display on , cursor on
#define LCD_8BIT_MODE 0x38 //1 cycle

//APIs 
void LCD_VidInit(void);
void LCD_VidSendCommand(u8 command);
void LCD_VidSendChar(u8 data);
void LCD_VidSendString(const char* str);
void LCD_VidSetCursor(u8 row , u8 col);
void LCD_VidClear(void);
void LCD_VidSendNumber(u8 num);

#endif