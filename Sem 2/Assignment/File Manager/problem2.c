/*
Two files DATA1 and DATA2 contain sorted lists of integers.
Write a program to produce a third file DATA which holds a single sorted, merged list of these two lists.
Use command line arguments to specify the file names.
*/

#include <stdio.h>

void create_and_fill_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Fatal Error: Could not create %s\n", filename);
        return ;
    }

    int count, current, previous;

    printf("\n------------------ Creating %s ------------------\n", filename);
    printf("How many integers do you want to enter for %s? ", filename);
    while (scanf("%d", &count) != 1 || count <= 0)
    {
        printf("[!] WARNING: Enter a valid positive integer for count: ");
        while (getchar() != '\n'); // Clear Buffer
    }

    int first_valid = 0;
    while (!first_valid)
    {
        printf("Enter 1 integer: ");
        if (scanf("%d", &previous) == 1)
        {
            fprintf(fp, "%d\n", previous);
            first_valid = 1;
        }
        else
        {
            printf("\n[!] WARNING: Only integers are allowed! Try again.\n");
            while (getchar() != '\n'); // clear Bufffer
        }
    }

    for (int i = 0; i < count-1; i++)
    {
        printf("Enter %d integer (must be >= %d): ", i + 2, previous);
        if (scanf("%d", &current) != 1) // Check if input is an integer
        {
            printf("[!] WARNING: Character/String/Special_Charater not allowed. Enter an integer! Try Again.\n");
            while (getchar() != '\n'); // Clear Buffer
            i--;  // Repeat this step
            continue;
        }

        if (current < previous) // Check if input is sorted
        {
            printf("\n[!] WARNING: Numbers must be in SORTED order (Greater than %d)! Try again.\n", previous);
            i--;
            continue;
        }

        fprintf(fp, "%d\n", current);
        previous = current;
    }
    fclose(fp);
    printf("[SUCCESS] %s created with sorted data.\n", filename);
}

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *fp3;
    char ch;
    int num1, num2;

    if (argc != 4)
    {
        printf("Usage: %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
        return 1;
    }

    fp1 = fopen(argv[1],"r");
    if (fp1 == NULL)
    {
        printf("\n%s not found. If you wish to create it? (Y/n): ", argv[1]);
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            create_and_fill_file(argv[1]);
            fp1 = fopen(argv[1], "r");
        }
        else
            return 1;
    }

    fp2 = fopen(argv[2], "r");
    if (fp2 == NULL)
    {
        printf("\n%s not found. If you wish to create? (Y/n): ", argv[2]);
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            create_and_fill_file(argv[2]);
            fp2 = fopen(argv[2], "r");
        }
        else
        {
            fclose(fp1);
            return 1;
        }
    }

    fp3 = fopen(argv[3], "w");

    int result1 = fscanf(fp1, "%d", &num1);
    int result2 = fscanf(fp2, "%d", &num2);

    while (result1 == 1 && result2 == 1)
    {
        if (num1 < num2)
        {
            fprintf(fp3, "%d\n", num1);
            result1 = fscanf(fp1, "%d", &num1);
        }
        else
        {
            fprintf(fp3, "%d\n", num2);
            result2 = fscanf(fp2, "%d", &num2);
        }
    } // it is stop when one of the file is end of file
    while (result1 == 1) // write the remaining numbers of the file which is not end of file
    {
        fprintf(fp3, "%d\n", num1);
        result1 = fscanf(fp1, "%d", &num1);
    }
    while (result2 == 1) // write the remaining numbers of the file which is not end of file
    {
        fprintf(fp3, "%d\n", num2);
        result2 = fscanf(fp2, "%d", &num2);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("\n[DONE] Files merged successfully into %s\n", argv[3]);
    return 0;
}