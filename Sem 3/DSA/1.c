// Implement menu-driven program to implement Stack using Array to perform all basic operations: PUSH, POP, PEEK, isEmpty, isFull, and DISPLAY.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (top == SIZE - 1)
        return 1;
    return 0;
}

int main()
{
    int ch;
    do
    {
        printf(" ====> Stack Operations <==== \n");
        printf(" 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isFull() == 1)
                printf("Stack is OverFlow ...\n");
            else
            {
                printf("Enter Your Value for Push: ");
                scanf("%d", &stack[++top]);
                printf("Element Push Successfully in Stack ....\n");
            }
            break;

        case 2:
            (isEmpty() == 1) ? printf("Stack is UnderFlow ...\n") : printf("%d Pop Successfully in Stack ....\n", stack[top--]);
            break;

        case 3:
            (isEmpty() == 1) ? printf("Stack is UnderFlow ...\n") : printf("%d is Peep in Stack ....\n", stack[top]);
            break;

        case 4:
            if (isEmpty() == 1)
                printf("Stack is UnderFlow ...\n");
            else
            {
                for (int i = top; i >= 0; i--)
                    printf("%d\t", stack[i]);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice ... \n");
        }
    } while (ch != 5);
    return 0;
}
