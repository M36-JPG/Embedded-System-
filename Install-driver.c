#include <stdio.h>

/* تعريف Registers (Simulation) */
unsigned int GPIO_DIR = 0;   // اتجاه البورت (0 = Input, 1 = Output)
unsigned int GPIO_DATA = 0;  // البيانات

/* تعريف الماكروز */
#define SET_BIT(REG, BIT)   (REG |= (1 << BIT))
#define CLR_BIT(REG, BIT)   (REG &= ~(1 << BIT))
#define READ_BIT(REG, BIT)  ((REG >> BIT) & 1)

/* Function: Initialize Pin Direction */
void GPIO_Init(int pin, int direction)
{
    if(direction == 1)
        SET_BIT(GPIO_DIR, pin);   // Output
    else
        CLR_BIT(GPIO_DIR, pin);   // Input
}

/* Function: Write to Pin */
void GPIO_Write(int pin, int value)
{
    if(value == 1)
        SET_BIT(GPIO_DATA, pin);  // High
    else
        CLR_BIT(GPIO_DATA, pin);  // Low
}

/* Function: Read from Pin */
int GPIO_Read(int pin)
{
    return READ_BIT(GPIO_DATA, pin);
}

/* Main للتجربة */
int main()
{
    GPIO_Init(2, 1);     // Pin 2 Output
    GPIO_Write(2, 1);    // High

    int val = GPIO_Read(2);
    printf("Pin Value = %d\n", val);

    return 0;
}
