// Implement menu-driven program to implement Circular Queue using Array to perform operations: INSERT (Enqueue), DELETE (Dequeue), and DISPLAY

#include <stdio.h>
int front = -1, rear = -1, circularQueue[5];

void enqueue()
{
    int value;

    printf("Enter Your Value: ");
    scanf("%d", &value);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("%d is inserted succefully ... \n", circularQueue[rear] = value);
    }

    else if (rear == front - 1)
        printf("Queue is Full ... \n");

    else if (front != 0)
    {
        if (rear == 5 - 1)
        {
            rear = 0;
            printf("%d is inserted succefully ... \n", circularQueue[rear] = value);
        }

        else
            printf("%d is inserted succefully ... \n", circularQueue[++rear] = value);
    }

    else if (rear == 5 - 1)
        printf("\n Queue Is Empty ... \n");

    else
        printf("%d is inserted succefully ... \n", circularQueue[++rear] = value);
}

int main()
{
    int ch;
    do
    {
        printf(" ====> Circular Queue Operations <==== \n");
        printf(" 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            (front == rear) ? printf("\n Queue Is Empty ... \n") : printf("\n %d Deleted Successfully ...\n", circularQueue[front++]);
            break;

        case 3:
            for (int i = front; i <= rear; i++)
                printf("%d \t", circularQueue[i]);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("You Have chhose Wrong Options");
            break;
        }
    } while (ch != 4);
    return 0;
}
