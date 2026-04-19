/*
 * File:   KEYPAD.c
 * Author: SPEED
 *
 * Created on April 18, 2026, 5:05 PM
 */

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include "KeyPad.h"
#include "LCD.h"
static u8 g_pendingKey = 0xFF;

void KEYPAD_VidInit(void){
    GPIO_VidSetPortDir(KEYPAD_Port,KEYPAD_Port_Dir);
    GPIO_VidSetPortValue(KEYPAD_Port , GPIO_HIGH); //Input pull-up
}

u8 KEYPAD_U8GetPressedKey(void){
    u8 loc_PinValue;
    u8 loc_PressedKey = 0xFF;
    u8 KEYPAD_COL_ARR[KEYPAD_COLNUM] = {KEYPAD_COL1 , KEYPAD_COL2 , KEYPAD_COL3 , KEYPAD_COL4};
    u8 KEYPAD_ROW_ARR[KEYPAD_ROWNUM] = {KEYPAD_ROW1 , KEYPAD_ROW2 , KEYPAD_ROW3 , KEYPAD_ROW4};
    u8 KEYPAD_ARR [KEYPAD_ROWNUM][KEYPAD_COLNUM] = KEYPAD_Arr;

    for(int i =0; i<KEYPAD_COLNUM; i++){
       GPIO_VidSetPinValue(KEYPAD_Port , KEYPAD_COL_ARR[i],GPIO_LOW);

       for(int j =0; j<KEYPAD_ROWNUM; j++){
        loc_PinValue = GPIO_U8GetPinValue(KEYPAD_Port , KEYPAD_ROW_ARR[j]);

        if(loc_PinValue == GPIO_LOW){
            loc_PressedKey = KEYPAD_ARR[j][i];
            while(loc_PinValue == GPIO_LOW){
                loc_PinValue = GPIO_U8GetPinValue(KEYPAD_Port , KEYPAD_ROW_ARR[j]);
            }
            _delay_ms(10);
        }
           GPIO_VidSetPinValue(KEYPAD_Port , KEYPAD_COL_ARR[i],GPIO_HIGH);
           return loc_PressedKey;
       }
          GPIO_VidSetPinValue(KEYPAD_Port , KEYPAD_COL_ARR[i],GPIO_HIGH);
    }
    return loc_PressedKey;
}
u8 KEYPAD_GetNumber(void)
{
    u8 number = 0;
    u8 key;

    while(1)
    {
        key = KEYPAD_U8GetPressedKey(); 
        if(key == 0xFF){
            continue;
        }

        if(key >= '0' && key <= '9')   
        {
            LCD_VidSendChar(key);         
            number = ( number * 10u ) + (key - '0'); 
        }
        else
        {
            g_pendingKey = key;
            return number;
        }
    }
}
u8 KEYPAD_GetOperator(void)
{
    u8 key;

    while(1)
    {
        if(g_pendingKey != 0xFF){
            key = g_pendingKey;
            g_pendingKey = 0xFF;
        }
        else{
            key = KEYPAD_U8GetPressedKey();
        }
        key = KEYPAD_U8GetPressedKey();   

        if(key == '+' || key == '-' || key == '*' || key == '/')
        {
            LCD_VidSendChar(key); 
            return key;        
        }
    }
}
