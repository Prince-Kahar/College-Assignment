// Write a program that reads a file containing integers and appends at its end the sum of all the integers.

#include <stdio.h>

int main()
{
    FILE *fp1;

    int num, sum = 0;
    char ch;
    char f1[50];

    printf("Enter file name: ");
    scanf("%s", f1);
    getchar();

    fp1 = fopen(f1, "w+");

    printf("Enter integer text for %s file (end with ~):\n", f1);
    while ((ch = getchar()) != '~')
        if (ch >= '0' && ch <= '9' || ch == '~' || ch == ' ') // allow only digits , ~ , and space
            fputc(ch, fp1);

    getchar();
    rewind(fp1);

    while (fscanf(fp1, "%d", &num) != EOF) // Read integer and sum
        sum += num;

    fclose(fp1);

    fp1 = fopen(f1, "a"); // open in append mode to add sum at the end
    if (fp1 == NULL)
    {
        printf("File is Not Open\n");
        return 1;
    }
    else
        printf("File is Opened Successfully in Append Mode\n");

    fprintf(fp1, "\nSum = %d", sum); // Add Sum at the end of file
    fclose(fp1);
    printf("Sum appended successfully\n");
    return 0;
}