/*
Write a program that prompts the user for two files, one containing a line of text known as source file and other, an empty file known as target file and then copies the contents of source file into target file.
Modify the program so that a specified character is deleted from the source file as it is copied to the target file.
*/

#include <stdio.h>

int main()
{
    FILE *src, *tgt;
    char ch1, ch2;

    src = fopen("source", "w+");

    printf("Enter text for source file (end with ~ and then enter ):\n");
    while ((ch1 = getchar()) != '~')
        fputc(ch1, src);

    rewind(src);
    tgt = fopen("target", "w");

    printf("Enter character to delete: ");
    scanf(" %c", &ch2); // Read the character to delete

    while ((ch1 = fgetc(src)) != EOF)
    {
        if (ch1 != ch2) // Skip the specified character
            fputc(ch1, tgt);
    }

    fclose(src);
    fclose(tgt);

    printf("File copied successfully\n");
    return 0;
}