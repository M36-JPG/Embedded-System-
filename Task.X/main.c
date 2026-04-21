/*
 * File:   main.c
 * Author: SPEED
 *
 * Created on April 18, 2026, 5:07 PM
 */


#include <xc.h>
#include "LCD.h"
#include "KEYPAD.h"
int main(void){
    LCD_VidInit();
    KEYPAD_VidInit();

    while(1){
        int num1 , num2 , result = 0;
        u8 opKey = 0xFF;
        u8 endKey = 0xFF;

        LCD_VidClear();

        num1 = KEYPAD_GetNumberWithTerminator(&opKey);
        if(opKey == 'C'){
            continue;
        }
        if(opKey != '+' && opKey != '-' && opKey != '*' && opKey != '/'){
            LCD_VidClear();
            LCD_VidSendString("Op Err");
            continue;
        }

        num2 = KEYPAD_GetNumberWithTerminator(&endKey);
        if(endKey == 'C'){
            continue;
        }
        if(endKey != '='){
            LCD_VidClear();
            LCD_VidSendString("Press =");
            continue;
        }

        switch(opKey)
        {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if(num2 == 0){
                    LCD_VidClear();
                    LCD_VidSendString("Math Error");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                LCD_VidClear();
                LCD_VidSendString("Op Err");
                continue;
        }

        LCD_VidClear();
        LCD_VidSendString("Result = ");
        LCD_VidSendNumber(result);
    }
}