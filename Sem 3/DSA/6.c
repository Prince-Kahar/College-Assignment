// Implement menu-driven program to implement Double Ended Queue (Dequeue) to perform operations for Input-Restricted and OutputRestricted Double Ended Queues using an array.

#include <stdio.h>
#define SIZE 5

int main()
{
    int q[SIZE], front = -1, rear = -1, type, choice, value;

    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);

            if (type == 1)
            {
                if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
                    printf("Queue is Full\n");
                else
                {
                    if (front == -1)
                        front = rear = 0;
                    else if (front == 0)
                        front = SIZE - 1;
                    else
                        front--;
                    q[front] = value;
                }
            }
            else
            {
                int side;
                printf("1. Front  2. Rear: ");
                scanf("%d", &side);

                if (side == 1)
                {
                    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
                        printf("Queue is Full\n");
                    else
                    {
                        if (front == -1)
                            front = rear = 0;
                        else if (front == 0)
                            front = SIZE - 1;
                        else
                            front--;
                        q[front] = value;
                    }
                }
                else if (side == 2)
                {
                    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
                        printf("Queue is Full\n");
                    else
                    {
                        if (front == -1)
                            front = rear = 0;
                        else if (rear == SIZE - 1)
                            rear = 0;
                        else
                            rear++;
                        q[rear] = value;
                    }
                }
                else
                    printf("Wrong choice\n");
            }
            break;

        case 2:
            if (type == 1)
            {
                int side;
                printf("1. Front  2. Rear: ");
                scanf("%d", &side);

                if (side == 1)
                    if (front == -1)
                        printf("Queue is Empty\n");
                    else
                    {
                        printf("Deleted: %d\n", q[front]);

                        if (front == rear)
                            front = rear = -1;
                        else if (front == SIZE - 1)
                            front = 0;
                        else
                            front++;
                    }
                else if (side == 2)
                    if (front == -1)
                        printf("Queue is Empty\n");
                    else
                    {
                        printf("Deleted: %d\n", q[rear]);

                        if (front == rear)
                            front = rear = -1;
                        else if (rear == 0)
                            rear = SIZE - 1;
                        else
                            rear--;
                    }
                else
                    printf("Wrong choice\n");
            }
            else if (front == -1)
                printf("Queue is Empty\n");
            else
            {
                printf("Deleted: %d\n", q[front]);

                if (front == rear)
                    front = rear = -1;
                else if (front == SIZE - 1)
                    front = 0;
                else
                    front++;
            }
            break;

        case 3:
            if (front == -1)
                printf("Queue is Empty\n");
            else
            {
                int i = front;
                while (1)
                {
                    printf("%d\t", q[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % SIZE;
                }
                printf("\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);
    return 0;
}