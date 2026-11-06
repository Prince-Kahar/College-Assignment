/*
Develop your own functions for performing following operations on strings:
    A. Copying one string to another
    B. Comparing two strings
    C. Adding a string to the end of another string
Write a driver program to test your functions.
*/

#include <stdio.h>
#include <string.h>

void copy_string(char dest[], char src[])
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

int compare_string(char str1[], char str2[])
{
    int i;
    for (i = 0; str1[i] == str2[i]; i++)
        if (str1[i] == '\0')
            return 0;
    return str1[i] - str2[i];
}

void concatenate_string(char dest[], const char src[])
{
    int i, j;
    for (i = 0; dest[i] != '\0'; i++); // Move to the end of the destination string
    for (j = 0; src[j] != '\0'; j++) // Copy characters from source string to destination string
    {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    char str1[100], str2[100], copy_str[100];

    printf("Enter your first string: ");
    scanf("%[^\n]", str1);

    printf("Enter your second string: ");
    scanf(" %[^\n]", str2);

    // Testing copyString function
    copy_string(copy_str, str1);
    printf("\nCopied first string: %s\n", copy_str);

    // Testing stringCompare function
    compare_string(str1, str2) == 0 ? printf("The strings are equal\n") : printf("The string are different\n");

    // Testing stringConcatenate function
    concatenate_string(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}