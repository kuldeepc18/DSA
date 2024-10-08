#include <stdio.h>
#include <string.h>

#define MAX 10

int top = -1;
int stk[MAX];
void push(char);
char pop();

int main()
{
    char exp[MAX], temp;
    int i, flag = 1;
    printf("Enter an expression: ");
    scanf("%d", &exp);
    for(i=0; i<strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '(' || temp == '{'))
                {
                    flag = 0;
                }
            }
        }
    }
    if (top >= 0)
    {
        flag = 0;
    }
    else if(flag == 1)
    {
        printf("\nValid Expression");
    }
    else
    {
        printf("\nInvalid Expression");
    }
    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        top++;
        stk[top] = c;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\n Stack Underflow");
    }
    else
    {
        return (stk[top--]);
    }
}