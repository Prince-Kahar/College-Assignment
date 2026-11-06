/*
Given an array of sorted list of integer numbers, Write a function to search for a particular item, using the method of binary search.
And also show how this function may be used in a program.
use pointers and pointer arithmetic.
*/

#include <stdio.h>

int check_sorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

int binarySearch(int *arr, int size, int find)
{
    int *low = arr;
    int *high = arr + size - 1;

    while (low <= high)
    {
        int *mid = low + (high - low) / 2;

        if (*mid == find)
            return (int)(mid - arr);
        else if (*mid < find)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int size, i, arr[100], key;

    printf("Enter Array Size : ");
    scanf("%d", &size);

    while (1)
    {
        printf("\nEnter Sorted Element \n");
        for (i = 0; i < size; i++)
        {
            printf("Enter %d Element : ", i + 1);
            scanf("%d", &arr[i]);
        }
        if (!check_sorted(arr, size))
        {
            printf("\nError! Please Enter Sorted Element\n");
            continue;
        }
        break;
    }

    printf("\nWhich Element You Have To Find : ");
    scanf("%d", &key);
    int result = binarySearch(arr, size, key);

    if (result != -1)
        printf("\nElement %d found at Position : %d\n", key, result + 1);
    else
        printf("\nElement not found.\n");
    return 0;
}