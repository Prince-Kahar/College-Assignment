/*
Write a program that requests for a file name and an integer, known as offset value.
The program then reads the file starting from the location specified by the offset value and prints the contents on the screen.

Note: If the offset value is a positive integer, then printing skips that many lines. If it is a negative number, it prints that many lines from the end of the file. An appropriate error message should be printed, if anything goes wrong.
*/

#include <stdio.h>
#include <stdlib.h>

#define max_lines 1000
#define max_len 256

int main()
{
    FILE *fp;

    char filename[100];
    char lines[max_lines][max_len];
    int offset, count = 0, i;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File is Not Open\n");
        return 1;
    }
    else
        printf("File is Opened Successfully\n");

    printf("Enter offset value (must be integer): ");

    while (scanf("%d", &offset) != 1)
    {
        printf("\n[!] Warning Enter Only Integer Number \n");
        printf("Please Enter Integer Offset Value : ");
        while(getchar() != '\n');
    }

    while (fgets(lines[count], max_len, fp) != NULL) // Read all lines into array
    {
        count++;
        if (count >= max_lines)
            break;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("Error: File is empty.\n");
        return 1;
    }
    /* Positive offset: skip lines from beginning */
    if (offset >= 0)
    {
        if (offset >= count)
        {
            printf("Error: Offset exceeds number of lines in file.\n");
            return 1;
        }
        for (i = offset; i < count; i++)
            printf("%s", lines[i]);
    }
    else
    {
        offset = -offset; // convert negative offset to the positive
        if (offset > count)
        {
            printf("Error: Offset exceeds number of lines.\n");
            return 1;
        }
        for (i = count - offset; i < count; i++)
            printf("%s", lines[i]);
    }
    return 0;
}