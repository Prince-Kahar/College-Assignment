// Write a program to copy the contents of one file into another.

#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;

    char ch;
    char f1[50], f2[50];

    printf("Enter first file name: ");
    scanf("%s", f1);
    printf("Enter second file name: ");
    scanf("%s", f2);

    fp1 = fopen(f1, "r");
    if (fp1 == NULL)
    {
        printf("\nError! %s is Not Open\n", f1);
        printf("\nIf you wish to create %s ( Y/n ) :- ", f1);
        char ch;
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            while (getchar() != '\n');

            fp1 = fopen(f1, "w+");
            printf("Enter text for %s (end with ~ and then enter) : ", f1);
            while ((ch = getchar()) != '~') // Read characters until '~' is encountered
                fputc(ch, fp1);

            rewind(fp1);
        }
        else
            return 1;
    }
    else
        printf("%s is Opened Successfully\n", f1);

    fp2 = fopen(f2, "w");

    if (fp2 == NULL)
    {
        printf("\nError! %s is Not Open\n", f2);
        return 1;
    }
    else
        printf("\n%s is Opened Successfully\n", f2);

    while ((ch = fgetc(fp1)) != EOF)
        fputc(ch, fp2);

    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}