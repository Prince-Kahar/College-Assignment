// Write a C program that prints the size of a structure and union data type that have same number and type of members.

#include <stdio.h>

struct Student
{
    char name[50];
    int roll_no;
    float marks;
}S;

union student
{
    char name[50];
    int roll_no;
    float marks;
}s;

int main()
{
    printf("The size of the struct is %lu bytes\n", sizeof(S));
    printf("The size of the union is %lu bytes\n", sizeof(s));
    return 0;
}