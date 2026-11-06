/*
Design a structure student_record to contain name, date of birth, and total marks obtained.
Use the date structure designed in problem4 to represent the date of birth.
Develop a program to read data for 10 students in a class and list them rank-wise.
*/

#include <stdio.h>
#define n 10

struct student_record
{
    char name[30];
    struct date
    {
        int day, month, year;
    } dob;
    float marks;
}s[n];

void input_student_record(struct student_record s[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of student %d\n", i + 1);
        printf("Name: ");
        scanf("%[^\n]s", s[i].name);

        printf("Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d", &s[i].dob.day, &s[i].dob.month, &s[i].dob.year);

        printf("Total Marks: ");
        scanf("%f", &s[i].marks);
        getchar();
        printf("\n");
    }
}

void sort_rankwise(struct student_record s[])
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].marks < s[j].marks)
            {
                struct student_record temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}

void display(struct student_record s[])
{
    printf("\nRANK-WISE STUDENT LIST\n");
    printf("------------------------------------------------------\n");
    printf("Rank  Name            DOB              Marks\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
        printf("%-5d %-15s %02d/%02d/%04d       %-10.2f\n", i + 1, s[i].name, s[i].dob.day, s[i].dob.month, s[i].dob.year, s[i].marks);
}

int main()
{
    input_student_record(s);
    sort_rankwise(s);
    display(s);

    return 0;
}