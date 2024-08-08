// PRIORITY QUEUE

#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *start = NULL;

struct node *insert(struct node *);
struct node *deleteNode(struct node *);
void display(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = deleteNode(start);
            break;
        case 3:
            display(start);
            break;
        case 4:
            exit(0); // You can use exit() to exit the program
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}

struct node *insert(struct node *start)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("\n Memory allocation failed.");
        return start;
    }

    printf("\n Enter data: ");
    scanf("%d", &temp->data);
    printf("\n Enter priority: ");
    scanf("%d", &temp->priority);

    if (start == NULL || temp->priority < start->priority)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL && ptr->next->priority <= temp->priority)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }

    return start;
}

struct node *deleteNode(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else
    {
        ptr = start;
        printf("\n Deleted item is: %d", ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}

void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        printf("\n PRIORITY QUEUE IS: ");
        while (ptr != NULL)
        {
            printf("\t%d[priority == %d]", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }
}
