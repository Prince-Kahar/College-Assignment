// Implement program to convert infix to postfix expression.

#include <stdio.h>
int main()
{
    char infix[200], postfix[200], stack[200];
    int top = -1, j = 0;

    printf("Enter Your Infix Expression: ");
    scanf("%[^\n]", infix);
    
    for (int i = 0; infix[i] != '\0'; i++)
    {
        switch (infix[i])
        {
        case '(':
            stack[++top] = infix[i];
            break;

        case ')':
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            stack[top--];
            break;

        case '^':
            while (stack[top] != '^')
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
            break;

        case '*':
        case '/':
            while (stack[top] == '^' || stack[top] == '*' || stack[top] == '/')
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
            break;

        case '+':
        case '-':
            while (stack[top] == '^' || stack[top] == '*' || stack[top] == '/' || stack[top] == '+' || stack[top] == '-')
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
            break;

        case ' ':
            continue;

        default:
            postfix[j++] = infix[i];
        }
    }

    while (stack[top] != -1)
    {
        if (stack[top] != '(')
            postfix[j++] = stack[top--];
        else
            stack[top--];
    }

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n\n", postfix);
    return 0;
}
