#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 10
char stack[max];
int top = -1;
void push(char stack[], char val)
{
    if (top == max - 1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top] = val;
    }
}
char pop()
{
    char val;
    if (top == -1)
        printf("\nStack Underflow");
    else
    {
        val = stack[top];
        top--;
    }
    return val;
}
int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
}
void InftoPost(char inf[], char post[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(post, "");
    while (inf[i] != '\0')
    {
        if (inf[i] == '(')
        {
            push(stack, inf[i]);
            i++;
        }
        else if (inf[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                post[j] = pop(stack);
                j++;
            }
            if (top == -1)
                printf("\nIncorrect Expression");
            temp = pop(stack);
            i++;
        }
        else if (isdigit(inf[i]) || isalpha(inf[i]))
        {
            post[j] = inf[i];
            i++;
            j++;
        }
        else if (inf[i] == '+' || inf[i] == '-' || inf[i] == '/' || inf[i] == '*' || inf[i] == '%')
        {
            while ((top != -1) && (stack[top] != '(') &&
                   (getPriority(stack[top]) > getPriority(inf[i])))
            {
                post[j] = pop(stack);
                j++;
            }
            push(stack, inf[i]);
            i++;
        }
        else
            printf("\nIncorrect Expression");
    }
    while ((top != -1) && (stack[top] != '('))
    {
        post[j] = pop(stack);
        j++;
    }
    post[j] = '\0';
}
float evaluatePostFix(char exp[])
{
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
            push(stack, (float)(exp[i] - '0'));
        else
        {
            op2 = pop(stack);
            op1 = pop(stack);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
            }
            push(stack, value);
        }
        i++;
    }
    return pop(stack);
}
void main()
{
    float v;
    char infix[10], postfix[10];
    printf("\nEnter an Expression: ");
    scanf("%s", &infix);
    strcpy(postfix, "");
    InftoPost(infix, postfix);
    printf("\nPostfix operation is: ");
    puts(postfix);
    v = evaluatePostFix(postfix);
    printf("Value of the postfix operation is: %f", v);
}