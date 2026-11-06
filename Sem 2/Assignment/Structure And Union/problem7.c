/*
Add a function called nextdate to the program designed in problem 4 to perform the fllowing task:
    A. Accepts two arguments, one of the structure data containing the present date and the second an integer that represents the number of days to be added to the present date.
    B. Adds the days to the present date and returns the structure containin the next date correctly.
Not :- that the next date may be in the next month or even the next year.

*/

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
} d;

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int days_in_month(int month, int year)
{
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && leap_year(year))
        return 29;

    return days_in_month[month];
}

int check_date(struct date d)
{
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > 31)
        return 0;

    if (d.day > days_in_month(d.month, d.year))
        return 0;

    return 1;
}
struct date nextdate(struct date current, int days_to_add)
{
    for (int i = 0; i < days_to_add; i++)
    {
        current.day++;
        if (current.day > days_in_month(current.month, current.year))
        {
            current.day = 1;
            current.month++;

            if (current.month > 12)
            {
                current.month = 1;
                current.year++;
            }
        }
    }
    return current;
}

int new_date(struct date *d, int days)
{
    for (int i = 0; i < days; i++)
        *d = nextdate(*d, 1);
    return 1;
}

void printDate(struct date d)
{
    char *month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("%s %d, %d\n", month_names[d.month], d.day, d.year);
}

int main()
{
    struct date d, updated_date;
    int days;

    while (1)
    {
        printf("Enter Date ( in given format ) ( DD / MM / YYYY): ");
        if (scanf("%d / %d / %d", &d.day, &d.month, &d.year) != 3)
        {
            printf("Error! Invalid date format ( Enter in DD / MM / YYYY format ) \n");
            while (getchar() != '\n');
            continue;
        }
        else
        {
            if (!check_date(d))
            {
                printf("Error! Invalid Date Entered\n");
                continue;
            }
            else
                break;
        }
    }

    printf("Enter number of days to add: ");
    scanf("%d", &days);

    new_date(&d, days);
    printf("Next date is:\n");
    printDate(d);

    return 0;
}
