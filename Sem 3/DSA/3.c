// Implement Program to Evaluate Prefix Expression.

#include <stdio.h>
#include <string.h>
int main()
{
    char prefix[200];
    int stack[200], top = -1, i, firstValue, secondValue;

    printf("Enter Your Prefix Expression: ");
    scanf("%[^\n]", prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (prefix[i] == ' ')
            continue;

        if (prefix[i] >= '0' && prefix[i] <= '9')
            stack[++top] = prefix[i] - '0';
        else
        {
            firstValue = pop();
            secondValue = pop();

            switch (prefix[i])
            {
            case '+':
                stack[++top] = firstValue + secondValue;
                break;

            case '-':
                stack[++top] = firstValue - secondValue;
                break;

            case '*':
                stack[++top] = firstValue * secondValue;
                break;

            case '/':
                if (secondValue == 0)
                {
                    printf("Division by Zero Error\n");
                    return 0;
                }
                stack[++top] = firstValue / secondValue;
                break;

            case '^':
                firstValue = 1;
                for (int j = 0; j < secondValue; j++)
                    firstValue = firstValue * secondValue;
                break;

            default:
                printf("Invalid Operator\n");
                return 0;
            }
        }
    }
    printf("Prefix Expression: %s\n", prefix);
    printf("Result: %d\n", stack[top--]);
    return 0;
}
