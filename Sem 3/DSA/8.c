// Implement menu-driven program to implement Doubly Linked List to perform insertion, deletion, and forward/backward traversal operations.

#include <stdio.h>
#include <stdlib.h>

struct doubly
{
    struct doubly *prevAddress;
    int data;
    struct doubly *nextAddress;
} *new, *head, *temp, *prev;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu();
void createNode();
void insert();
void delete();
void deleteFromFront();
void deleteFromRear();
void display();
void ForwardDisplay();
void BackwardDisplay();

int main()
{
    clearScreen();
    int choice;

    do
    {

        printf(" ----------------------- Doubly Linked List Operations ----------------------- \n");
        printf(" | 1. Insert                                                                 | \n");
        printf(" | 2. Delete                                                                 | \n");
        printf(" | 3. Forward Traversal                                                      | \n");
        printf(" | 4. Backward Traversal                                                     | \n");
        printf(" | 5. Exit                                                                   | \n");
        printf(" ----------------------------------------------------------------------------- \n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            insert();
            break;

        case 2:
            clearScreen();
            delete();
            break;

        case 3:
            clearScreen();
            ForwardDisplay();
            break;

        case 4:
            clearScreen();
            BackwardDisplay();
            break;

        case 5:
            clearScreen();
            printf("Byyyy \n");
            return;

        default:
            clearScreen();
            printf("You Have Chyhode Wrong Operations ... \n");
        }
    } while (choice != 5);
    return 0;
}

void createNode()
{
    new = (struct doubly *)malloc(sizeof(struct doubly));

    if (new == NULL)
    {
        printf("Memory Allocated Failed ... \n");
        return;
    }

    int item;

    printf("Enter Your value: ");
    scanf("%d", &item);

    new->prevAddress = NULL;
    new->data = item;
    new->nextAddress = NULL;

    printf("%d is inserted successfully ... \n", item);
}

void insert()
{
    int choice;

    do
    {
        printf(" ----------------- Insert Operations ----------------- \n");
        printf(" | 1. Insert From Front                              | \n");
        printf(" | 2. Insert From Rear                               | \n");
        printf(" | 0. Go back                                        | \n");
        printf(" ----------------------------------------------------- \n");

        printf("Enter Your Insert choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            createNode();

            if (head != NULL)
                head->prevAddress = new;

            new->nextAddress = head;
            head = new;
            break;

        case 2:
            clearScreen();
            if (head == NULL)
            {
                insertFromFront();
                return;
            }

            createNode();

            temp = head;
            while (temp->nextAddress != NULL)
                temp = temp->nextAddress;

            temp->nextAddress = new;
            new->prevAddress = temp;
            break;

        case 0:
            clearScreen();
            printf("Byyy \n");
            break;

        default:
            clearScreen();
            printf("You Have Choose Wrong operations ... \n");
            break;
        }

    } while (choice != 0);
}

void delete()
{
    int choice;

    do
    {
        printf(" ----------------- Delete Operations ----------------- \n");
        printf(" | 1. Delete From Front                              | \n");
        printf(" | 2. Delete From Rear                               | \n");
        printf(" | 3. Delete From Spcific Location                   | \n");
        printf(" | 0. Go back                                        | \n");
        printf(" ----------------------------------------------------- \n");

        printf("Enter Your Delete choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            deleteFromFront();
            break;

        case 2:
            clearScreen();
            deleteFromRear();
            break;

        case 3:
            clearScreen();
            // deletePos();
            break;

        case 0:
            clearScreen();
            printf("Byyy \n");
            break;

        default:
            clearScreen();
            printf("You Have Choose Wrong operations ... \n");
            break;
        }

    } while (choice != 0);
}

void deleteFromFront()
{
    if (head == NULL)
    {
        printf("Doubly Linked List is UnderFlow ... \n");
        return;
    }

    if (head->nextAddress == NULL)
    {
        printf("%d is deleted suceesfully ... \n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    printf("%d is deleted suceesfully ... \n", head->data);

    head = head->nextAddress;

    if (head->nextAddress != NULL)
        head->prevAddress = NULL;

    free(temp);
}

void deleteFromRear()
{
    if (head == NULL)
    {
        printf("Doubly Linked List is UnderFlow ... \n");
        return;
    }

    if (head->nextAddress == NULL)
    {
        printf("%d is deleted successfully ... \n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->nextAddress != NULL)
    {
        prev = temp;
        temp = temp->nextAddress;
    }

    prev->nextAddress = NULL;

    printf("%d is deleted successfully ... \n", temp->data);

    free(temp);
}

void ForwardDisplay()
{
    if (head == NULL)
    {
        printf("Doubly Linked List is Empty ... \n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->nextAddress;
    }
    printf("\n");
}

void BackwardDisplay()
{
    if (head == NULL)
    {
        printf("Doubly Linked List is Empty ... \n");
        return;
    }

    temp = head;

    while (temp->nextAddress != NULL)
        temp = temp->nextAddress;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prevAddress;
    }

    printf("\n");
}
