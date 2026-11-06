/*
Design a function update that would accept the data structure designed in problem 1 and increments time by one second and returns the new time .
Hint : if the incremenet results in 60 seconds, then the second memeber is set to zero and the minute memeber is incremented by one. Then, if the reult is 60 minutes, the minute memeber is set to zero and the hour memeber is incremented by one. Finally when the hour becomes 24, it is set to zero.
*/

#include <stdio.h>

struct time_struct
{
    int hour, minute, second;
}ts;

void input_time(struct time_struct *ts)
{
    printf("Enter hour : ");
    scanf("%d", &ts->hour);
    printf("Enter Minute : ");
    scanf("%d", &ts->minute);
    printf("Enter Second : ");
    scanf("%d", &ts->second);
}

int update(struct time_struct *ts)
{
    ts->second++;
    if (ts->second == 60)
    {
        ts->second = 00;
        ts->minute++;
        
        if (ts->minute == 60)
        {
            ts->minute = 00;
            ts->hour++;
            
            if( ts->hour == 24)
                ts-> hour = 0;
        }
    }
}

int main()
{
    input_time(&ts);
    
    update(&ts);
    printf("Update Time (+1s): \n%d : %d : %d \n", ts.hour, ts.minute, ts.second);
    return 0;
}