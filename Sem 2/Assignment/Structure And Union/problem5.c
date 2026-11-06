/*
Design a function update that accepts the data structure designed in Problem 4 to incremenet the date by one day and return the new date. The following rules are applicable:
    A. If the data is the last day in a month, month should be incremented
    B. If it is the day in December, the year should be incremented
    C. There are 29 days in Feburary of a leap year
*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
} d;

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

int update_date(struct date *d)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leap_year(d->year))
        days[2] = 29;

    d->day++;
    if (d->day > days[d->month])
    {
        d->day = 1;
        d->month++;

        if (d->month > 12)
        {
            d->month = 1;
            d->year++;
        }
    }
    return 1;
}

void print_date(struct date d)
{
    char *month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("%s %d, %d\n", month_names[d.month], d.day, d.year);
}

int main()
{
    while (1)
    {
        input_date(&d);

        if (!check_date(d))
        {
            printf("\nError! Invalid Date Entered\n");
            continue;
        }
        else
        {
            printf("\nSuccess! Valid Date Entered\n");
            break;
        }
    }
    
    update_date(&d);
    printf("Updated Date ( +1 day) : ");
    print_date(d);

    return 0;
}