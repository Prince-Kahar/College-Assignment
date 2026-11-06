// Write a program that appends one file at the end of another.

#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch1, ch2;
    char f1[50], f2[50];

    printf("Enter first file name: ");
    scanf("%s", f1);
    printf("Enter second file name: ");
    scanf("%s", f2);
    getchar();

    fp1 = fopen(f1, "w");
    fp2 = fopen(f2, "w+");

    printf("Enter text for %s file (end with ~):\n", f1);
    while ((ch1 = getchar()) != '~')
        fputc(ch1, fp1);
    getchar();

    printf("Enter text for %s file (end with ~):\n", f2);
    while ((ch2 = getchar()) != '~')
        fputc(ch2, fp2);

    fclose(fp1);
    rewind(fp2);
    fp1 = fopen(f1, "a");

    while ((ch2 = fgetc(fp2)) != EOF)
        fputc(ch2, fp1);

    fclose(fp1);
    fclose(fp2);

    printf("File appended successfully\n");
    return 0;
}