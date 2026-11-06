/*
In preparing the calendar for a year we need to know whether that particular year is leap year or not. 
Design a function leap( ) that receives the year as a parameter and returns an appropriate message.
What modifications are required if we want to use the function in preparing the actual calendar?
*/

#include <stdio.h>

void leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);
}

int main()
{
    int year;
    printf("Enter a year: ");
    if (scanf("%d", &year) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    
    leap(year);
    return 0;
}