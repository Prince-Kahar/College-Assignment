/*
Modify the input function used in problem 4 such that it reads a value that represents the date in the form of a long integer, like 19450815 for the date 15-8-1945 (August 15, 1945) and assigns suitable values to the members day, month , and year.
Use suitable algorithm to convert the long integer 19450815 into year, month and day.
*/

#include <stdio.h>

struct date
{
    int day, month, year;
} d;

void read_date(struct date *d)
{
    long int date;
    printf("Enter date in YYYYMMDD format: ");
    scanf("%ld", &date);

    d->year = date / 10000;
    d->month = (date % 10000) / 100;
    d->day = date % 100;
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
    printf("\nYear = %04d \nMonth = %02d \nDay = %02d\n", d.year, d.month, d.day);
}

int main()
{
    while (1)
    {
        read_date(&d);

        if (!check_date(d))
        {
            printf("\nError! Invalid Date Entered\n");
            continue;
        }
        else
        {
            print_date(d);
            break;
        }
    }
    return 0;
}