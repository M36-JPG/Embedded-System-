#ifndef GPIO_INTERFACING_H
#define GPIO_INTERFACING_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_REG.h"

#define GPIO_PORTB 0
#define GPIO_PORTC 1
#define GPIO_PORTD 2

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

#define GPIO_INPUT 0
#define GPIO_OUTPUT 1
#define GPIO_ALL_INPUT 0x00
#define GPIO_ALL_OUTPUT 0xFF

#define GPIO_LOW 0
#define GPIO_HIGH 1
#define GPIO_ALL_LOW 0x00
#define GPIO_ALL_HIGH 0xFF

void GPIO_VidSetPinDir(u8 port , u8 pin , u8 dir);
void GPIO_VidSetPinValue(u8 port , u8 pin , u8 value);
void GPIO_VidTogglePin(u8 port , u8 pin);

void GPIO_VidSetPortDir(u8 port , u8 dir);
void GPIO_VidSetPortValue(u8 port , u8 value);

u8 GPIO_U8GetPinValue(u8 port , u8 pin);
u8 GPIO_U8GetPortValue(u8 port);


#endif