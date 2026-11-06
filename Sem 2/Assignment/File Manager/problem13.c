// Write a C program that reads characters from a file and prints their ASCII codes.

#include <stdio.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("Character\tASCII Code\n");    
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        printf("%c\t\t%d\n", ch, (int)ch);

    fclose(fp);
    return 0;
}