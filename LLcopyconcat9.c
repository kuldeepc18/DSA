#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void append(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *copyList(struct Node *head)
{
    struct Node *newHead = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        append(&newHead, current->data);
        current = current->next;
    }

    return newHead;
}

void concatenateLists(struct Node **list1, struct Node *list2)
{
    if (*list1 == NULL)
    {
        *list1 = list2;
    }
    else
    {
        struct Node *temp = *list1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = list2;
    }
}

struct Node *splitList(struct Node **head, int position)
{
    struct Node *current = *head;
    struct Node *newHead = NULL;

    if (*head == NULL || position <= 0)
    {
        return NULL;
    }

    for (int i = 1; i < position && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        return NULL;
    }

    newHead = current->next;
    current->next = NULL;

    return newHead;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    for (int i = 1; i <= 5; i++)
    {
        append(&list1, i);
    }

    printf("Original List 1: ");
    display(list1);

    struct Node *copiedList = copyList(list1);
    printf("\nCopied List: ");
    display(copiedList);

    for (int i = 6; i <= 10; i++)
    {
        append(&list2, i);
    }

    printf("\nOriginal List 2: ");
    display(list2);

    concatenateLists(&list1, list2);
    printf("\nConcatenated List 1: ");
    display(list1);

    struct Node *splitListResult = splitList(&list1, 3);
    printf("\nList 1 after Split at Position 3: ");
    display(list1);
    printf("List 2 after Split at Position 3: ");
    display(splitListResult);

    list1 = reverseList(list1);
    printf("\nReversed List 1: ");
    display(list1);

    int nodeCount = countNodes(list1);
    printf("\nNumber of nodes in the reversed list: %d\n", nodeCount);

    return 0;
}