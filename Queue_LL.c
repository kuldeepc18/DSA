#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q; // Global queue pointer

void create_queue(struct queue *);
struct queue *insert_queue(struct queue *, int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
    int val, option;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the number to be inserted in the queue: ");
            scanf("%d", &val);
            q = insert_queue(q, val);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = peek(q);
            if (val != -1)
            {
                printf("\n The value at the front of the queue is: %d", val);
            }
            break;
        case 4:
            q = display(q);
            break;
        }
    } while (option != 5);

    free(q); // Free allocated memory before exiting
    return 0;
}

void create_queue(struct queue *q)
{
    q->rear = NULL;
    q->front = NULL;
}

struct queue *insert_queue(struct queue *q, int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    return q;
}

struct queue *delete_element(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (q->front == NULL)
    {
        printf("\n Underflow");
    }
    else
    {
        q->front = q->front->next;
        printf("\n The value deleted is: %d", ptr->data);
        free(ptr);
    }
    return q;
}

struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
    return q;
}

int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\n Queue is empty");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}
