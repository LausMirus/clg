#include <stdio.h>
#include <ctype.h>

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

/* Infix to Postfix Conversion */
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* If operand, append to postfix */
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        /* If left parenthesis, push */
        else if (ch == '(')
        {
            push(ch);
        }

        /* If right parenthesis */
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            /* Pop and discard '(' */
            if (top != -1 && stack[top] == '(')
            {
                pop();
            }
        }

        /* If operator */
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                    (precedence(stack[top]) == precedence(ch) &&
                     !isRightAssociative(ch))))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
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

/* Evaluate Postfix Expression */
int evaluatePostfix(char postfix[])
{
    int i;
    int operand1, operand2, result;
    char ch;

    valueTop = -1;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        /* If operand */
        if (isdigit(ch))
        {
            pushValue(ch - '0');
        }

        /* If operator */
        else
        {
            operand2 = popValue();
            operand1 = popValue();

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
    char infix[100], postfix[100];
    int result;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    /* Convert infix to postfix */
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    /* Evaluate postfix */
    result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}