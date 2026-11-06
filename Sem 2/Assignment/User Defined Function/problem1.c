/*
Write a function exchange to interchange the values of two variables, say x and y. 
Illustrate the use of this function, in a calling function. 
Assume that x and y are defined as global variables.
*/

#include <stdio.h>

int a = 10, b = 20;

void exchange(void)
{
    b = a + b;
    a = b - a;
    b = b - a;
}

int main()
{
    printf("Before exchange: a = %d, b = %d\n", a, b);
    exchange();
    printf("After exchange: a = %d, b = %d\n", a, b);
    return 0;
}