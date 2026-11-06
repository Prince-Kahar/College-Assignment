/*
Use the data structure defined in problem 4 to store two dates.
Develop a function that will take these two dates as input and compares them.
    A. it returns 1, if the date1 is earlier than date2
    B. it returns 0, if date1 is later date
*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
} d1, d2;

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int update_date(struct date d)
{
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.year < 1 || d.day < 1 || d.day > days_in_month[d.month] || d.month < 1 || d.month > 12)
        return 0;

    if (d.month == 2 && leap_year(d.year))
        days_in_month[2] = 29;

    return 1;
}

int compare(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return 1;
    else if (d1.year > d2.year)
        return 0;

    if (d1.month < d2.month)
        return 1;
    else if (d1.month > d2.month)
        return 0;

    if (d1.day < d2.day)
        return 1;
    else
        return 0;
}

int main()
{
    printf("Enter First Date ( in given format ) ( MM / DD / YYYY): ");
    if (scanf("%d / %d / %d", &d1.day, &d1.month, &d1.year) != 3)
    {
        printf("Error! Invalid date format ( Enter in MM / DD / YYYY format ) \n");
        return 0;
    } // check fromat

    if (!update_date(d1)) // check leap year
    {
        printf("Error! Invalid date entered.\n");
        return 0;
    }

    printf("Enter Second Date ( in given format ) ( MM / DD / YYYY): ");
    if (scanf("%d / %d / %d", &d2.day, &d2.month, &d2.year) != 3)
    {
        printf("Error! Invalid date format ( Enter in MM / DD / YYYY format ) \n");
        return 0;
    } // check fromat

    if (!update_date(d2)) // check leap year
    {
        printf("Error! Invalid date entered.\n");
        return 0;
    }

    compare(d1, d2) == 1 ? printf("Date1 is earlier than Date2\n") : printf("Date1 is later than Date2\n");
    return 0;
}