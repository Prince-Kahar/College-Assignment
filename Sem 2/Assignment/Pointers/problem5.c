/*
Using pointers, write a function that receives a character string and a character as argument and deletes all occurrences of this character in the string . 
The function should return the corrected string with no holes.
*/

#include <stdio.h>

void remove_char(char *str, char removable_char)
{
    char *src = str, *dest = str;
    while (*src != '\0')
    {
        if (*src != removable_char)
        {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

int main()
{
    char str[100], removeableChar;
    printf("Enter Your String: ");
    scanf("%[^\n]s", str);

    printf("Which Character You Have to Remove form the String : ");
    scanf(" %c", &removeableChar);
    
    remove_char(str, removeableChar);
    
    printf("%s\n", str);
    return 0;
}