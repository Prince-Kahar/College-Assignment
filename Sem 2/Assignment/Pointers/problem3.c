// Write a function that receives a sorted array of integers and an integer value, and inserts the value in its correct place.

#include <stdio.h>
#include <stdlib.h>

int check_sorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

int insert_element(int *arr, int *size, int newElement)
{
    int i;
    for (i = *size - 1; i >= 0 && *(arr + i) > newElement; i--)
        *(arr + i + 1) = *(arr + i);
    *(arr + i + 1) = newElement;
    (*size)++;
    return 1;
}

int main()
{
    int size, i, new_element;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc((size + 1) * sizeof(int));

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

    printf("\nEnter a Value to insert : ");
    scanf("%d", &new_element);
    
    insert_element(arr, &size, new_element);
    printf("Updated Array : \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}