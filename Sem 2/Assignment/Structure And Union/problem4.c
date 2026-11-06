/*
Define a structure data type named data contining three integer memebers day. month, and year. 
Develop an interactive modular program to perform the following tasks:
    A. To read data into structure members by a function
    B. To validate the data entered by another function
    C. TO print the data in the format
            April 29, 2002
by a third function.

The input data should be three integers like 29, 4, and 2002 corresponding to day, month, and year. 

Examples of invalid data:
            31, 4, 2002 - April has only 30 days
            29, 2, 2002 - 2002 is not a leap year
*/

#include <stdio.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
}d;

void input_date(struct date *d)
{
    printf("Enter Day (1-31): ");
    scanf("%d", &d->day);
    printf("Enter Month (1-12): ");
    scanf("%d", &d->month);
    printf("Enter Year (e.g., 2002): ");
    scanf("%d", &d->year);
}

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int check_date(struct date d)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > 31)
        return 0;

    if (leap_year(d.year))
        days[2] = 29;

    if (d.day > days[d.month])
        return 0;

    return 1;
}

void print_date(struct date d)
{
    char month_names[13][15] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Formatted Date: %s %d, %d\n", month_names[d.month], d.day, d.year);
}

int main()
{
    int validation = 0;
    input_date(&d);

    if (check_date(d))
    {
        printf("\nSuccess! The date entered is a valid date.\n");
        print_date(d);
    }
    else
        printf("\nError! The date entered is a invalid date.\n");

    return 0;
}