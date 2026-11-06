// Write a C program that uses the pointer increment operations to demonstrate the scale factor

#include <stdio.h>

int main()
{
    int integer = 0, *ptr_integer = &integer;
    char charater = 'a', *ptr_character = &charater;
    double doubLe = 0.0, *ptr_doubLe = &doubLe;

    printf("Int Pointer     :   %p -> After Increment Operations : %p (Difference: %ld bytes)\n", ptr_integer, ptr_integer + 1, (long)(ptr_integer + 1) - (long)ptr_integer);
    printf("Char Pointer    :   %p -> After Increment Operations : %p (Difference: %ld bytes)\n", ptr_character, ptr_character + 1, (long)(ptr_character + 1) - (long)ptr_character);
    printf("Double Pointer  :   %p -> After Increment Operations : %p (Difference: %ld bytes)\n", ptr_doubLe, ptr_doubLe + 1, (long)(ptr_doubLe + 1) - (long)ptr_doubLe);
    
    return 0;
}