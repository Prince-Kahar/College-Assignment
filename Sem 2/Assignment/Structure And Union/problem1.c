/*
Define a structure data type called time_struct containing three members integer hour, integer minute and integer second . 
Develop a program that would assign values to the individual members and display the time in the following form:
                16 : 40 : 51 
*/

#include<stdio.h>

struct time_struct
{
    int hour, minute, second;
}ts;

int main()
{
    ts.hour = 16;
    ts.minute = 40;
    ts.second = 51;
    
    printf("%02d : %02d : %02d \n", ts.hour, ts.minute, ts.second);
    return 0;
}