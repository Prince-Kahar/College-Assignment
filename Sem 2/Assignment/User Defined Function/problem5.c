/*
The Fibonacci numbers are defined recursively as follows:
        	F1 = 1
			F2 = 1
			Fn = Fn-1 + Fn-2 , n>2
Write a function that will generate and print the first n Fibonacci numbers. 
Test the function for n = 5, 10, and 15.
*/

#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 0)
    {
        printf("Please enter a positive integer.");
        return -1;
    }
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        int next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
    return 0;
}

int main()
{
    printf("The first 5 Fibonacci numbers are: ");
    fibonacci(5);
    printf("\n");
    printf("The first 10 Fibonacci numbers are: ");
    fibonacci(10);
    printf("\n");
    printf("The first 15 Fibonacci numbers are: ");
    fibonacci(15);
    printf("\n");
    return 0;
}