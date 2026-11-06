/*
We know that the roots of a quadratic equation of the form
    ax^2 + bx + c = 0
are given by the following equations :
    x1 = -b + square root(b2 - 4ac) / 2a
    x2 = -b - square root(b2 - 4ac) / 2a
Write a function to calculate the roots. The function must use two pointer parameters, one to receive the coefficients a, b, and c, and the other to send the roots to the calling function.
*/

#include <stdio.h>
#include <math.h>

float* quadratic_equation(float *coefficients, float *roots)
{
    float a = *coefficients, b = *(coefficients + 1), c = *(coefficients + 2);
    float discriminant = b * b - 4 * a * c;
    if (discriminant >= 0)
    {
        *(roots) = (-b + sqrt(discriminant)) / (2 * a);
        *(roots + 1) = (-b - sqrt(discriminant)) / (2 * a);
    }
    return roots;
}

int main()
{
    float coefficients[3], roots[2];
    printf("Enter Coefficients of a, b and c : ");
    scanf("%f %f %f", &coefficients[0], &coefficients[1], &coefficients[2]);

    quadratic_equation(coefficients, roots);
    printf("These Quadratic Equation Roots Are %.3f and %.3f", roots[0], roots[1]);
    printf("\n");
    return 0;
}