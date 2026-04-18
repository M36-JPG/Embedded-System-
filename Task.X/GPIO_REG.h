#ifndef GPIO_REG_H
#define GPIO_REG_H

#include "STD_TYPES.h"

//PORT B
#define PORTB_REG *((volatile u8*)0x25)
#define PINB_REG *((volatile u8*)0x23)
#define DDRB_REG *((volatile u8*)0x24)

//PORT C
#define PORTC_REG *((volatile u8*)0x28)
#define PINC_REG *((volatile u8*)0x26)
#define DDRC_REG *((volatile u8*)0x27)

#define PORTD_REG *((volatile u8*)0x2B)
#define PIND_REG *((volatile u8*)0x29)
#define DDRD_REG *((volatile u8*)0x2A)

#endif
