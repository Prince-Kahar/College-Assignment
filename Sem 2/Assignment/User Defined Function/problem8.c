// Write a function that will scan a character string passed as an argument and convert all lowercase characters into their uppercase equivalents.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_to_uppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    convert_to_uppercase(str);
    printf("Uppercase string: %s", str);
    return 0;
}   