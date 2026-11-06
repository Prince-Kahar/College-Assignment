/*
Write a program to read in an array of names and to sort them in alphabetical order.
Use sort function that receives pointers to the function strcmp and swap.sort in turn should call these functions via the pointers.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i;

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char *name[], int n, int (*cmp)(const char *, const char *))
{
    for (i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(name[i], name[j]) > 0)
                swap(&name[i], &name[j]);
}

int main()
{
    char **names = (char **)malloc(3 * sizeof(char *));

    printf("Enter 3 Name : ");
    for (i = 0; i < 3; i++)
    {
        names[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s", names[i]);
    }

    sort(names, 3, strcmp);

    printf("\nsorted names :\n");
    for (i = 0; i < 3; i++)
        printf("%s\n", names[i]);

    free(names);

    return 0;
}