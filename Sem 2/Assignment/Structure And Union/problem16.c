/*
Write a C program that prints the size of a structure data types.
*/

#include <stdio.h>

struct student
{
    char name[50];
    int roll_no;
    float marks;
}s;

int main()
{
    printf("The size of the student is %lu bytes\n",sizeof(s));
    return 0;
}