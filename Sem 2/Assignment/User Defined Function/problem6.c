/*
Write a function that will round a floating-point number to an indicated decimal place.
For example the number 17.457 would yield the value 17.46 when it is rounded off to two decimal places.
*/

#include <stdio.h>
#include <math.h>

void rounded(float num, int places)
{
    num = round(num * pow(10, places)) / pow(10, places);
    printf("Rounded value: %.*f\n", places, num);
}

int main()
{
    float num;
    int decimal;
    printf("Enter number to round: ");
    scanf("%f", &num);
    printf("Enter number of decimal places to round to: ");
    scanf("%d", &decimal);
    rounded(num, decimal);
    return 0;
}