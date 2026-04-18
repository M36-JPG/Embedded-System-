/*
 * File:   GPIO.c
 * Author: SPEED
 *
 * Created on April 18, 2026, 3:14 PM
 */


#include <avr/io.h>
#include "GPIO_INTERFACING.h"

// PIN APIs

void GPIO_VidSetPinDir(u8 port , u8 pin , u8 dir){
  if(pin <= 7){
     if( dir == GPIO_OUTPUT){
       switch(port){
        case GPIO_PORTB: SET_BIT(DDRB_REG , pin);
        break;
        case GPIO_PORTC: SET_BIT(DDRC_REG , pin);
        break;
        case GPIO_PORTD: SET_BIT(DDRD_REG , pin);
        break;
       }
    }
    else if(dir == GPIO_INPUT){
        switch (port)
        {
            case GPIO_PORTB: CLR_BIT(DDRB_REG , pin);
            break;
            case GPIO_PORTC: CLR_BIT(DDRC_REG , pin);
            break;
            case GPIO_PORTD: CLR_BIT(DDRD_REG , pin);
            break;
        }
    }
  }
    
}

void GPIO_VidSetPinValue(u8 port , u8 pin , u8 value){
    if(pin <= 7){
        if(value == GPIO_HIGH){
            switch(port){
                case GPIO_PORTB:SET_BIT(PORTB_REG , pin);
                break;
                case GPIO_PORTC:SET_BIT(PORTC_REG , pin);
                break;
                case GPIO_PORTD:SET_BIT(PORTD_REG , pin);
                break;
            }
        }
        else if(value == GPIO_LOW){
            switch(port){
              case GPIO_PORTB:CLR_BIT(PORTB_REG , pin);
                break;
                case GPIO_PORTC:CLR_BIT(PORTC_REG , pin);
                break;
                case GPIO_PORTD:CLR_BIT(PORTD_REG , pin);
                break;
            }
             
        }
    }
}

void GPIO_VidTogglePinValue(u8 port , u8 pin){
    if(pin <= 7){
        switch(port){
            case GPIO_PORTB: TOGGLE_BIT(PORTB_REG , pin);
            break;
             case GPIO_PORTC: TOGGLE_BIT(PORTC_REG , pin);
            break;
             case GPIO_PORTD: TOGGLE_BIT(PORTD_REG , pin);
            break;
        }
    }
}

u8 GPIO_U8GetPinValue(u8 port , u8 pin){
   u8 local_res = 0;
   if(pin <= 7){
    switch(port){
        case GPIO_PORTB: local_res = GET_BIT(PINB_REG , pin);
        break;
        case GPIO_PORTC: local_res = GET_BIT(PINC_REG , pin);
        break;
        case GPIO_PORTD: local_res = GET_BIT(PIND_REG , pin);
        break;
    }
   }
   return local_res;
}

//PORT APIs
void GPIO_VidSetPortDir(u8 port , u8 dir){
     switch(port){
            case GPIO_PORTB : DDRB_REG = dir;
            break;
            case GPIO_PORTC : DDRC_REG = dir;
            break;
            case GPIO_PORTD : DDRD_REG = dir;
            break;
   }
}

void GPIO_VidSetPortValue(u8 port , u8 value){
    switch(port){
        case GPIO_PORTB : PORTB_REG = value;
        break;
        case GPIO_PORTC : PORTC_REG = value;
        break;
        case GPIO_PORTD : PORTD_REG = value;
        break;
    }
}

u8 GPIO_U8GetPortValue(u8 port){
    u8 loc_result = 0;
    switch(port){
        case GPIO_PORTB : loc_result = PINB_REG ;
        break;
        case GPIO_PORTC : loc_result = PINC_REG ;
        break;
        case GPIO_PORTD : loc_result = PIND_REG ;
        break;
    }
    return loc_result;
}


