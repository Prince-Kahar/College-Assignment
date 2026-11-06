// Write a C program to insert a substring into another string by using function and pointers.

#include <stdio.h>
#include <string.h>

void insertSubString(char *main_str, char *ptr_sub_str, int position)
{
    char temp[200];
    char *ptr_main_str = main_str;
    char *ptr_temp = temp;

    for (int i = 0; i < position; i++)
        *ptr_temp++ = *ptr_main_str++; // copy from main string to position to temp

    while (*ptr_sub_str)
        *ptr_temp++ = *ptr_sub_str++; // copy from sub string to temp where we left above loop

    while (*ptr_main_str)
        *ptr_temp++ = *ptr_main_str++; // copy from remaining main str to temp where we left above loop

    *ptr_temp = '\0';
    strcpy(main_str, temp); // copy string from temp to main string
}

int main()
{
    char str[100], sub_str[100];
    int position;

    printf("Enter Your String : ");
    scanf("%[^\n]s", str);
    getchar();
    printf("Enter Your SubString : ");
    scanf("%[^\n]s", sub_str);

    printf("Enter the Position to Insert at ( 1 to %lu ) : ",strlen(str)  );
    scanf("%d", &position);

    printf("\nOriginal String : %s\n", str);
    insertSubString(str, sub_str, position);
    printf("\nAfter Insertion SubString : %s\n", str);
    
    return 0;
}