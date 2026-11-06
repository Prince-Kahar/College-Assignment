/* 
Design a function locate ( ) that takes two character arrays s1 and s2 and one integer value m as parameters and inserts the string s2 into s1 immediately after the index m . 
Write a program to test the function using a real-life situation. 
(Hint: s2 may be a missing word in s1 that represents a line of text).
*/

#include <stdio.h>
#include <string.h>

char* locate(char s1[], char s2[], int m)
{
    char temp[200];
    int i, j = 0;

    for (i = 0; i <= m; i++)
        temp[j++] = s1[i]; // copy characters from s1 to temp until index m

    for (i = 0; s2[i] != '\0'; i++)
        temp[j++] = s2[i]; // copy characters from s2 to temp

    for (i = m + 1; s1[i] != '\0'; i++)
        temp[j++] = s1[i]; // copy remaining characters from s1 to temp

    temp[j] = '\0';
    strcpy(s1, temp); // copy modified string back to s1

    return s1;
}

int main()
{
    char str1[200], str2[100];
    int m;

    printf("Enter the first string (str1): ");
    scanf("%[^\n]s", str1);
    printf("Enter the second string (str2): ");
    scanf(" %[^\n]s", str2);
    
    printf("Enter the index (m) after which to insert str2 into str1: ");
    scanf("%d", &m);
    
    locate(str1, str2, m);
    printf("The modified string is: %s\n", str1);
    return 0;
}