/*
 * File:   main.c
 * Author: SPEED
 *
 * Created on April 18, 2026, 5:07 PM
 */


#include <xc.h>
#include "LCD.h"
#include "KeyPad.h"
#include <stdio.h>
int main(void){
    LCD_VidInit();
    KEYPAD_VidInit();
    int num1 , num2 , result;    
    char operator ;  
    
    num1 = KEYPAD_GetNumber();   
    
    operator = KEYPAD_GetOperator();  
    
    num2 = KEYPAD_GetNumber(); 
     switch(operator)
    {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if(num2 == 0) 
                result = 0;   // handle divide by zero
            else 
                result = num1 / num2; 
            break;
        default: result = 0; break;
    }
    LCD_VidClear();
    LCD_VidSendString("Result = ");
    LCD_VidSendNumber(result);
    while(1);
}
