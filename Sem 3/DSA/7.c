// Implement menu-driven program to implement Singly Linked List to perform operations including insertion & deletion (at given position), searching, traversal.

#include <stdio.h>

struct Singly
{
    int info;
    struct Singly *next;
} *head = NULL, *node, *temp;

void insertAtPos()
{
    int pos;
    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    node = (struct Singly *)malloc(sizeof(struct Singly));

    if (node == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("Enter Value: ");
    scanf("%d", node->info);

    node->next = NULL;

    if (pos == 1)
    {
        node->next = head;
        head = node;
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid Position\n");
            free(node);
            return;
        }
        node->next = temp->next;
        temp->next = node;
    }
    printf("Inserted Successfully\n");
}

void deleteAtPos()
{
    int pos, i;
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Enter Position to Delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        temp = head;
        head = head->next;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid Position\n");
            return;
        }
        node = temp->next;
        temp->next = node->next;
        temp = node;
    }
    printf("Deleted Value: %d\n", temp->info);
    free(temp);
}

void search()
{
    int value, pos = 1, found = 0;
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Enter Value to Search: ");
    scanf("%d", &value);

    temp = head;
    while (temp != NULL)
    {
        if (temp->info == value)
        {
            printf("Value Found at Position %d\n", pos);
            found = 1;
        }

        temp = temp->next;
        pos++;
    }
    if (found == 0)
        printf("Value Not Found.\n");
}

int main()
{
    int choice;
    do
    {
        printf(" ====> Singly Linked List <====\n");
        printf(" 1. Insert At Given Position\n");
        printf(" 2. Deletion At Given Position\n");
        printf(" 3. Searching\n");
        printf(" 4. Traversal\n");
        printf(" 5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtPos();
            break;

        case 2:
            deleteAtPos();
            break;

        case 3:
            search();
            break;

        case 4:
            if (head == NULL)
            {
                printf(" Singly Linked List is Empty\n");
                return;
            }
            temp = head;
            while (temp != NULL)
            {
                printf("%d\t", temp->info);
                temp = temp->next;
            }
            break;

        case 5:
            printf("Exiting\n");
            break;

        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}
