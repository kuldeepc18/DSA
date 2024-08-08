#include <stdio.h>

#define MAX 10
void push();
void pop();
void display();
void peek();

int Stack[MAX], TOP = -1;
int main()
{
    int value, choice;
    while(1)
    {
        printf("\nMenu:\n ");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                    printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: 
                    pop();
                    break;
            case 3:
                    peek();
                    break;
            case 4: 
                    display();
                    break;
            default: 
                    printf("Wrong selection!!");
        }
    }
}

void push(int value)
{
    if(TOP == MAX - 1)
    {
        printf("Overflow!!");
    }
    else
    {
        TOP++;
        Stack[TOP] = value;
        printf("Value is stored in stack\n");
    }
}

void pop()
{
    if(TOP == -1)
    {
        printf("Stack is empty!!");
    }
    else
    {
        printf("Value is deletd from stack\n");
        TOP--;
    }
}

void peek()
{
    if(TOP == -1)
    {
        printf("Stack is empty!!");
    }
    else
    {
        printf("The top value in the stack is: %d", Stack[TOP]);
    }
}

void display()
{
    if(TOP == -1)
    {
        printf("\nThere is nothing to display");
    }
    else
    {
        printf("\nELements of the stack are: \n");
        for(int i =  TOP; i>=0; i--)
        {
            printf(" %d ", Stack[i]);
        }
    }
}