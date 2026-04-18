#ifndef CALCULATOR_H
#define CALCULATOR_H
int calculate(int num1, int num2, char operator)
{
    switch(operator)
    {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if(num2 == 0) return 0; // handle divide by zero
            else return num1 / num2;
    }
}

#endif