#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);
int front, rear = -1;

int main()
{
    int option, value;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek an element");
        printf("\n4. Display the queue");
        printf("\n5. Exit");
        printf("\n Enter your option");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("\n The number deleted is: %d", value);
            }
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("\n The first element in the queue is: %d", value);
            }
            break;
        case 4:
            display();
            break;
        }
    } while (value != 5);
    return 0;
}

void enqueue()
{
    int num;
    printf("\n Enter the number to be inserted in the queue: ");
    scanf("%d", &num);
    if (rear = MAX - 1)
    {
        printf("\n Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front, rear = 0;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
        {
            front, rear = -1;
        }
        return val;
    }
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}