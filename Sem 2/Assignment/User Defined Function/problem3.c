/*
Use recursive function calls to evaluate
        f(x) = x - pow(x,3)/3! + pow(x,5)/5! - pow(x,7)/7! + .....
*/

#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

float evaluate(int x, int power, int i, int terms)
// x = value of x, power = current power, i = current term number, terms = total number of terms to evaluate
{
    if (power > terms * 2 - 1) // Highest power is 2 * terms - 1
        return 0;
    float term = pow(x, power) / factorial(power);
    if (i % 2 == 0)
        return -term + evaluate(x, power + 2, i + 1, terms); // if terms is even then negative
    else
        return term + evaluate(x, power + 2, i + 1, terms); // if terms is odd then positive
}

int main()
{
    int x, terms;

    printf("Enter the value of x : ");
    scanf("%d", &x) != 1;
    printf("Enter the number of terms to evaluate : ");
    if(scanf("%d", &terms) != 1)
    {
        printf("Error reading terms value\n");
        return 1;
    }

    printf("The value of f(x) is : ");
    printf("%f\n", evaluate(x, 1, 1, terms));
    return 0;
}