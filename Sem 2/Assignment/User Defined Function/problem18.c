/*
Write a function that takes an integer parameter m representing the month number of the year and returns the corresponding name of the month.
For instance, if m = 3, the month is March. Test your program.
*/

#include <stdio.h>

char *month_name(int m)
{
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (m < 1 || m > 12)
    {
        printf("Error! Invalid month\n");
        return NULL;
    }
    return months[m - 1];
}

int main()
{
    int m;
    printf("Enter month number (1-12): ");
    if (scanf("%d", &m) != 1)
    /*
    Here Check condition !
    If the input is not an integer, scanf will return a value different from 1.
    And go to if block.
    */
    {
        printf("Invalid input.\n");
        return 1;
    }

    char *name = month_name(m);
    name != NULL ? printf("Month Name is %s\n", name) : printf("Error! Can't Retrive Month Name .\n");
    return 0;
}