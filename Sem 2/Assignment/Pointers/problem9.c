// Write a function ( using a pointer parameter ) that reverses the elements of a given array.

#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void reverses_array(int *arr, int n)
{
    int *left = arr;          // starting point
    int *right = arr + n - 1; // ending point
    while (left < right)
    {
        swap(left, right);
        left++;
        right--;
    }
}

int main()
{
    int size, i;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc((size + 1) * sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &arr[i]);
    }

    reverses_array(arr, size);
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}