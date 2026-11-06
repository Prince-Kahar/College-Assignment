/*
Write a function ( using pointer parameters ) that compares two integer arrays to see whether they are identical.
The function returns 1 if they are identical, 0 otherwise.
*/

#include <stdio.h>

void input(int *arr, int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter array%d[%d]: ", n, i);
        scanf("%d", &arr[i]);
    }
}

int comapare_two_integer(int *arr1, int *arr2, int arr1size, int arr2size)
{
    if (arr1size != arr2size)
        return 0;
    else
        for (int i = 0; i < arr1size; i++)
            if (*(arr1 + i) != *(arr2 + i))
                return 0;
}

int main()
{
    int arr1_size, arr2_size, i, j, arr1[100], arr2[100];
    printf("Enter Array 1 Size : ");
    scanf("%d", &arr1_size);

    printf("Enter Array 2 Size : ");
    scanf("%d", &arr2_size);
    if (arr1_size == arr2_size)
    {
        input(arr1, arr1_size, 1);
        printf("\n");
        input(arr2, arr2_size, 1);

        int b = comapare_two_integer(arr1, arr2, arr1_size, arr2_size);
        if (b == 0)
            printf("Both Array are Diffrenet\n");
        else
            printf("Both Array are Identical\n");
    }
    else
        printf("Both Array Size are Differenet\n");
        
    return 0;
}