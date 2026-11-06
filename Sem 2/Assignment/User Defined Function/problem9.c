/*
Develop a top_down modular program to implement a calculator. The program should request the user to input two numbers and display one of the following as per the desire of the user:
    A. Sum of the numbers
    B. Difference of the numbers
    C. Product of the numbers
    D. Division of the numbers
Provide separate functions for performing various tasks such as reading, calculating and displaying. Calculating module should call second level modules to perform the individual mathematical operations.
The main function should have only function calls.
*/

#include <stdio.h>
#define sum(a, b) ((a + b))
#define difference(a, b) ((a - b))
#define product(a, b) ((a * b))
#define division(a, b) ((b != 0) ? (a / b) : (printf("Error: Division by zero!\n"), 0))

void reading(float *a, float *b)
{
    printf("Enter two numbers: ");
    scanf("%f %f", a, b);
}

char operation()
{
    char choice;
    printf("\nChoose operation:\n");
    printf("A. Sum\n");
    printf("B. Difference\n");
    printf("C. Product\n");
    printf("D. Division\n");
    printf("Enter your choice (A/B/C/D): ");
    scanf(" %c", &choice);
    return choice;
}

void displaying(float result)
{
    printf("Result: %.2f\n", result);
}

void calculating(float a, float b, char operation)
{
    float result;
    switch (operation)
    {
    case 'A':
    case 'a':
        result = sum(a, b);
        break;
    case 'B':
    case 'b':
        result = difference(a, b);
        break;
    case 'C':
    case 'c':
        result = product(a, b);
        break;
    case 'D':
    case 'd':
        result = division(a, b);
        break;
    default:
        printf("Error! Invalid operation!\n");
        return;
    }
    displaying(result);
}

int main()
{
    float num1, num2;
    reading(&num1, &num2);
    calculating(num1, num2, operation());
    return 0;
}