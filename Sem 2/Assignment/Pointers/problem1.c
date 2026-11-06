// write a program using pointers to read in an array of integers and print its elements in reverse order.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i;
    printf("Enter Array Size : ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    int *ptr = arr;

    for (i = 0; i < size; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", (ptr + i));
    }

    printf("\nReverse Order : ");
    for (i = size - 1; i >= 0; i--)
        printf("%d\t", *(ptr + i));
    printf("\n");

    free(arr);
    return 0;
}