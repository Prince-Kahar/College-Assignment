/*
Write a function that receives a floating point value x and returns it as a value rounded to two nearest decimal places. 
For example, the value 123.4567 will be rounded to 123.46 
(Hint: Seek help of one of the math functions available in math library).
*/

#include <stdio.h>

void rounded(float x)
{
    printf("Rounded value: %.2f\n", x);
}

int main(void)
{
    float x;
    printf("Enter a floating point value: ");
    if (scanf("%f", &x) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    rounded(x);
    return 0;
}