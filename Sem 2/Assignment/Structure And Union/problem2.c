// Modify the problem 1 such that a function is used to input values to the members and another function to display the time.

#include <stdio.h>

struct time_struct
{
    int hour, minute, second;
}ts;

void input_time(struct time_struct * ts)
{
    printf("Enter hour : ");
    scanf("%d", &ts->hour);
    printf("Enter Minute : ");
    scanf("%d", &ts->minute);
    printf("Enter Second : ");
    scanf("%d", &ts->second);
}

int main()
{
    input_time(&ts);
    printf("%02d : %02d : %02d \n", ts.hour, ts.minute, ts.second);
    return 0;
}