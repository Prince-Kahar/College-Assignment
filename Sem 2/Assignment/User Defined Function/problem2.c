/*
Write a function space(x) that can be used to provide a space of x positions between two output numbers. 
Demonstrate its application.
*/

#include <stdio.h>

void space(int x)
{
    for (int i = 0; i < x; i++)
        printf(" ");
}

int main()
{
    int spaces, num1, num2;
    printf("Enter the first number : ");
    scanf("%d", &num1);
    printf("Enter the second number : ");
    scanf("%d", &num2);
    printf("How many spaces you have include between two numbers : ");
    scanf("%d", &spaces);
    printf("%d", num1);
    space(spaces);
    printf("%d\n", num2);
    return 0;
}