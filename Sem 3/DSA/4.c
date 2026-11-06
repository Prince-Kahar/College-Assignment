// Implement menu-driven program to implement Simple Queue using Array to perform operations: INSERT (Enqueue), DELETE (Dequeue), PEEK, and DISPLAY.

#include <stdio.h>
int main()
{
    int front = -1, rear = -1, simpleQueue[5], ch;
    do
    {
        printf(" ====> Simple Queue Operations <==== \n");
        printf(" 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (rear == 5 - 1)
                printf("Simple Queue is Empty ... \n");
            else
            {
                printf("Enter Your Value: ");
                scanf("%d", &simpleQueue[++rear]);
                front = 0;
                printf("%d is inserted succeffully ... \n", simpleQueue[rear]);
            }
            break;

        case 2:
            if (front == rear)
            {
                front = rear = -1;
                printf("Queue is Empty ... \n");
            }
            else
                printf("%d is deleted succeffully ... \n", simpleQueue[front++]);
            break;

        case 3:
            (front == -1) ? printf("Simple Queue is Empty ... \n") : printf("%d is peeked ... \n", simpleQueue[front]);
            break;

        case 4:
            if (front == -1)
                printf("Simple Queue is Empty ... \n");
            else
            {
                for (int i = front; i <= rear; i++)
                    printf("%d\t", simpleQueue[i]);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            break;
        }
    } while (ch != 5);
    return 0;
}
