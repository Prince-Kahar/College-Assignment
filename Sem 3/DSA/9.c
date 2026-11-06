// Implement menu-driven program to perform Searching Techniques to search for an element in an array using both Linear Search and Binary Search algorithms.

#include <stdio.h>
int main()
{
    int choice, arr[5], value, found = 0, low = 0, high = 5 - 1, mid;
    do
    {
        printf("\n====> Searching Techniques <====\n");
        printf(" 1. Input Array\n 2. Linear Search\n 3. Binary Search\n 4. Display Array\n 5. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter %d Elements in Sorted Order:\n", 5);
            for (int i = 0; i < 5; i++)
                scanf("%d", &arr[i]);
            printf("Array Inserted Successfully\n");
            break;

        case 2:
            printf("Enter Value to Search: ");
            scanf("%d", &value);

            for (int i = 0; i < 5; i++)
                if (arr[i] == value)
                {
                    printf("Value Found at Position %d\n", i + 1);
                    found = 1;
                    break;
                }
            if (found == 0)
                printf("Value Not Found\n");
            break;

        case 3:
            printf("Enter Value to Search: ");
            scanf("%d", &value);

            while (low <= high)
            {
                mid = (low + high) / 2;
                if (arr[mid] == value)
                {
                    printf("Value Found at Position %d\n", mid + 1);
                    found = 1;
                    break;
                }
                else if (arr[mid] < value)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if (found == 0)
                printf("Value Not Found\n");
            break;

        case 4:
            printf("Array Elements:\n");

            for (int i = 0; i < 5; i++)
                printf("%d\t", arr[i]);
            printf("\n");
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
