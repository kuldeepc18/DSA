#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(int data)
{
    struct node *newNode = createNode(data);
    if (start == NULL)
    {
        start = newNode;
        start->next = start;
        start->prev = start;
    }
    else
    {
        struct node *temp = start->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = start;
        start->prev = newNode;
    }
}

void insertBegin(int data)
{
    struct node *newNode = createNode(data);
    if (start == NULL)
    {
        start = newNode;
        start->next = start;
        start->prev = start;
    }
    else
    {
        struct node *temp = start->prev;
        newNode->next = start;
        newNode->prev = temp;
        start->prev = newNode;
        temp->next = newNode;
        start = newNode;
    }
}

void insertAfter(int data, int afterData)
{
    struct node *newNode = createNode(data);
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    do
    {
        if (temp->data == afterData)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != start);
    printf("Element not found in the list.\n");
}

void insertBefore(int data, int beforeData)
{
    struct node *newNode = createNode(data);
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    do
    {
        if (temp->data == beforeData)
        {
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
            if (temp == start)
            {
                start = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != start);
    printf("Element not found in the list.\n");
}

void deleteBegin()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        start = start->next;
        start->prev = temp->prev;
        temp->prev->next = start;
        free(temp);
    }
}

void deleteEnd()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start->prev;
    if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        temp->prev->next = start;
        start->prev = temp->prev;
        free(temp);
    }
}

void deleteAfter(int afterData)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    do
    {
        if (temp->data == afterData)
        {
            struct node *del = temp->next;
            temp->next = del->next;
            del->next->prev = temp;
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != start);
    printf("Element not found in the list.\n");
}

void deleteBefore(int beforeData)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    do
    {
        if (temp->data == beforeData)
        {
            struct node *del = temp->prev;
            del->prev->next = temp;
            temp->prev = del->prev;
            free(del);
            if (temp == start)
            {
                start = temp->prev;
            }
            return;
        }
        temp = temp->next;
    } while (temp != start);
    printf("Element not found in the list.\n");
}

void display()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

int main()
{
    int choice, data, afterData, beforeData;

    do
    {
        printf("\nMENU:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete after a node\n");
        printf("8. Delete before a node\n");
        printf("9. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at the end: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 2:
            printf("Enter value to insert at the beginning: ");
            scanf("%d", &data);
            insertBegin(data);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            printf("Enter value after which to insert: ");
            scanf("%d", &afterData);
            insertAfter(data, afterData);
            break;
        case 4:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            printf("Enter value before which to insert: ");
            scanf("%d", &beforeData);
            insertBefore(data, beforeData);
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("Enter value after which to delete: ");
            scanf("%d", &afterData);
            deleteAfter(afterData);
            break;
        case 8:
            printf("Enter value before which to delete: ");
            scanf("%d", &beforeData);
            deleteBefore(beforeData);
            break;
        case 9:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
