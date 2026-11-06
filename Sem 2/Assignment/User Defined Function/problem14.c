/*
Develop a top-down modular program that will perform the following tasks:
    A. Read two integer arrays with unsorted elements.
    B. Sort them in ascending order
    C. Merge the sorted arrays
    D. Print the sorted list
Use functions for carrying out each of the above tasks. The main function should have only function calls.
*/

#include <stdio.h>

void input_array(int array[], int size)
{
    printf("\nEnter Unsorted Element : \n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");
}

void sort_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = array[i], min_index = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < min)
            {
                min = array[j];
                min_index = j;
            }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

void merge_arrays(int array1[], int array2[], int result[], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        result[i] = array1[i];
    for (j = 0; j < n; j++)
        result[i + j] = array2[j];
}

void print_array(int array[], int size)
{
    printf("Array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void operations()
{
    int m, n;
    printf("Enter size of array 1 and array 2 : ");
    scanf("%d %d", &m, &n);

    int array1[m], array2[n];

    printf("Input for array 1:\n");
    input_array(array1, m);

    printf("Input for array 2:\n");
    input_array(array2, n);

    sort_array(array1, m);
    sort_array(array2, n);

    int result[m + n];
    merge_arrays(array1, array2, result, m, n);
    sort_array(result, m + n);

    print_array(result, m + n);
}

int main()
{
    operations();
    return 0;
}