// Implement menu-driven program to perform Advanced Sorting Techniques to sort an array of integers using Quick Sort and Merge Sort.

#include <stdio.h>
#define SIZE 5

int arr[SIZE];

void input();
void display();
void quickSort(int, int);
int partition(int, int);
void mergeSort(int, int);
void merge(int, int, int);

int main()
{
    int choice;

    do
    {
        printf("\n====> Advanced Sorting Techniques <====\n");
        printf("1. Input Array\n");
        printf("2. Quick Sort\n");
        printf("3. Merge Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input();
            break;

        case 2:
            quickSort(0, SIZE - 1);
            printf("Array Sorted Using Quick Sort\n");
            display();
            break;

        case 3:
            mergeSort(0, SIZE - 1);
            printf("Array Sorted Using Merge Sort\n");
            display();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 5);

    return 0;
}

void input()
{
    int i;

    printf("Enter %d Elements:\n", SIZE);

    for (i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    printf("Array Inserted Successfully\n");
}

void display()
{
    int i;

    printf("Array Elements:\n");

    for (i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}

int partition(int low, int high)
{
    int pivot, i, j, temp;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(low, high);

        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

void mergeSort(int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int temp[SIZE];
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}
