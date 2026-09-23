#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

int valueStack[100];
int valueTop = -1;

/* Push character onto stack */
void push(char ch)
{
    top++;
    stack[top] = ch;
}

/* Pop character from stack */
char pop()
{
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

/* Return precedence of operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

/* Check whether operator is right associative */
int isRightAssociative(char ch)
{
    if (ch == '^')
        return 1;
    else
        return 0;
}

/* Reverse a string */
void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Infix to Prefix Conversion */
void infixToPrefix(char infix[], char prefix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    /* Scan infix expression from right to left */
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        ch = infix[i];

        /* If operand, append to prefix */
        if (isalnum(ch))
        {
            prefix[j] = ch;
            j++;
        }

        /* If right parenthesis, push */
        else if (ch == ')')
        {
            push(ch);
        }

        /* If left parenthesis */
        else if (ch == '(')
        {
            while (top != -1 && stack[top] != ')')
            {
                prefix[j] = pop();
                j++;
            }

            /* Pop and discard ')' */
            if (top != -1 && stack[top] == ')')
            {
                pop();
            }
        }

        /* If operator */
        else
        {
            while (top != -1 &&
                   stack[top] != ')' &&
                   (precedence(stack[top]) > precedence(ch) ||
                    (precedence(stack[top]) == precedence(ch) &&
                     isRightAssociative(ch))))
            {
                prefix[j] = pop();
                j++;
            }

            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';

    /* Reverse the result */
    reverse(prefix);
}

/* Push integer onto value stack */
void pushValue(int value)
{
    valueTop++;
    valueStack[valueTop] = value;
}

/* Pop integer from value stack */
int popValue()
{
    int value;

    value = valueStack[valueTop];
    valueTop--;

    return value;
}

/* Evaluate Prefix Expression */
int evaluatePrefix(char prefix[])
{
    int i;
    int operand1, operand2, result;
    char ch;

    valueTop = -1;

    /* Scan prefix expression from right to left */
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        ch = prefix[i];

        /* If operand */
        if (isdigit(ch))
        {
            pushValue(ch - '0');
        }

        /* If operator */
        else
        {
            operand1 = popValue();
            operand2 = popValue();

            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '%':
                    result = operand1 % operand2;
                    break;

                case '^':
                    result = 1;

                    while (operand2 > 0)
                    {
                        result = result * operand1;
                        operand2--;
                    }

                    break;
            }

            pushValue(result);
        }
    }

    return popValue();
}

int main()
{
    char infix[100], prefix[100];
    int result;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    /* Convert infix to prefix */
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    /* Evaluate prefix */
    result = evaluatePrefix(prefix);

    printf("Result = %d\n", result);

    return 0;
}