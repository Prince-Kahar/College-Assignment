// Write a C program for demonstrating operations on individual structure members using pointer notation.

#include <stdio.h>

struct student
{
    int roll_no;
    float marks;
}s,*ptr;

int main()
{
    ptr = &s;
    ptr->roll_no = 101;
    ptr->marks = 88.50;

    printf("Roll Number : %d\n", ptr->roll_no);
    printf("Marks       : %.2f\n", ptr->marks);

    return 0;
}
