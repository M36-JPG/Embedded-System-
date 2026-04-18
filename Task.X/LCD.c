/*
 * File:   LCD.c
 * Author: SPEED
 *
 * Created on April 18, 2026, 5:02 PM
 */


#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
static void LCD_EnablePulse(void){
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_E_PIN , GPIO_HIGH);
    _delay_ms(5);
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_E_PIN , GPIO_LOW);
}

void LCD_VidInit(void){
    GPIO_VidSetPortDir(LCD_DATA_PORT , GPIO_ALL_OUTPUT);
    GPIO_VidSetPinDir(LCD_CONTROL_PORT, LCD_RS_PIN , GPIO_OUTPUT);
    GPIO_VidSetPinDir(LCD_CONTROL_PORT, LCD_RW_PIN , GPIO_OUTPUT);
    GPIO_VidSetPinDir(LCD_CONTROL_PORT, LCD_E_PIN , GPIO_OUTPUT);

    _delay_ms(60);
    LCD_VidSendCommand(LCD_8BIT_MODE); // Using 8 data bus , meaning 1 cycle
    LCD_VidSendCommand(LCD_DIS_ON); //Without cursor 
    //LCD_VidSendCommand(LCD_Dis_ON); // With cursor
    LCD_VidSendCommand(LCD_CLR_DIS);
    LCD_VidSendCommand(LCD_ENTRY_MODE); // Cursor from left to right
}

void LCD_VidSendCommand(u8 command){
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN , GPIO_LOW);
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN , GPIO_LOW);
    GPIO_VidSetPortValue(LCD_DATA_PORT , command);
    LCD_EnablePulse();
}

void LCD_VidSendChar(u8 data){
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN , GPIO_HIGH); //high bec it's data
    GPIO_VidSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN , GPIO_LOW); //low bec it's write
    GPIO_VidSetPortValue(LCD_DATA_PORT , data);
    LCD_EnablePulse();
}

void LCD_VidSendString(const char* str){
    while(*str){
        LCD_VidSendChar(*str++); // it loops on the previous function
    }
}

void LCD_VidSetCursor(u8 row , u8 col){ // for specfic location
    if(row == 0){//first row
      LCD_VidSendCommand(0x80 +col);
    }
    else{ // second row
       LCD_VidSendCommand(0x0C +col);
    }
}

void LCD_VidClear(void){
    LCD_VidSendCommand(LCD_CLR_DIS);
    _delay_ms(5);
}

void LCD_VidSendNumber(u8 num)
{
    u8 temp[16];         
    sprintf(temp, "%d", num); 
    LCD_VidSendString(temp);   
}
