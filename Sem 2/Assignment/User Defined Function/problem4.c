/*
An n_order polynomial can be evaluated as follows:
        P = (.....(((a 0 x+a 1 )x+a 2 )x+a 3 )x+...+a n)
Write a function to evaluate the polynomial, using an array variable. 
Test it using a main program.
*/

#include <stdio.h>

float evaluate_the_polynomial(float a[], int n, float x)
{
    float p = a[0];
    for (int i = 1; i <= n; i++)
        p = p * x + a[i];
    return p;
}

int main()
{
    int n;
    float x;
    printf("Enter polynomial (N) : ");
    scanf("%d", &n);

    float coeff[n + 1];
    printf("Enter %d Coefficicents : \n", n);
    for (int i = 0; i <= n; i++)
    {
        printf("Enter coefficients[%d] : ", i);
        scanf("%f", &coeff[i]);
    }
    
    printf("Enter The Value of X ( that is multiply ) : ");
    scanf("%f", &x);
    
    printf("Answer P(%f) is %f \n", x, evaluate_the_polynomial(coeff, n, x));
    return 0;
}