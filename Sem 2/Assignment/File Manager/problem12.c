/*
Write a C program that uses getw function to read integer values from one file.
Subsequently, it uses the putw function to write the integer values in reverse order in another file.
*/

#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char f1[50], f2[50];
    int a[100], n = 0, i, value, num;

    printf("Enter name for Input File: ");
    scanf("%s", f1);
    fp1 = fopen(f1, "wb+");

    printf("How many integers do you want to enter? ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &value);
        putw(value, fp1); // Writing integer in binary
    }

    rewind(fp1);
    printf("\nEnter name for Output (Reverse) File: ");
    scanf("%s", f2);
    fp2 = fopen(f2, "wb+");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("File opening error!");
        return 1;
    }

    /* Read integers from file using getw() */
    while ((value = getw(fp1)) != EOF)
        a[n++] = value;

    /* Write integers in reverse order using putw() */
    for (i = n - 1; i >= 0; i--)
        putw(a[i], fp2);

    fclose(fp1);

    printf("\n--- Contents of %s (Reversed) ---\n", f2);
    rewind(fp2);
    while ((value = getw(fp2)) != EOF)
        printf("%d ", value); // Now printing to screen
    printf("\n");

    fclose(fp2);
    printf("Integers written in reverse order successfully in %s \n", f2);
    return 0;
}