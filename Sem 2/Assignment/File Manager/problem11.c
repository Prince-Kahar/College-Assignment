// Write a C program that uses file handling methods to store records of mixed data in a file.

#include <stdio.h>

struct student
{
    int roll;
    char name[30];
    float marks;
}s;

int main()
{
    FILE *fp;
    
    int i, n;

    fp = fopen("records.txt", "w");

    if (fp == NULL)
    {
        printf("File is Not Open\n");
        return 1;
    }
    else
        printf("File is Opened Successfully\n");

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s.roll);
        getchar();
        printf("Name: ");
        scanf("%[^\n]s", s.name);
        printf("Marks: ");
        scanf("%f", &s.marks);

        fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
    printf("\nRecords stored successfully in file.\n");
    return 0;
}