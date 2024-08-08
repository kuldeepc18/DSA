#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_CLL(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_before(struct node *start);
struct node *delete_after(struct node *start);
struct node *search_Cll(struct node *start);
struct node *delete_CLL(struct node *start);

int main()
{
    int choice;
    while(1)
    {
        printf("\n***** Main Menu *****");
        printf("\n1. Create a circular linkedlist:");
        printf("\n2. display");
        printf("\n3. Insert at the beginning.");
        printf("\n4. Insert at the end.");
        printf("\n5. Insert before a given node.");
        printf("\n6. Insert after a given node.");
        printf("\n7. Delete at the beginning.");
        printf("\n8. Delete at the end.");
        printf("\n9. Delete before a given node.");
        printf("\n10. Delete after a given node.");
        printf("\n11. Dearch a node in the circular linkedlist.");
        printf("\n12. Delete the circular linkedlist.");
        printf("\n13. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create_CLL(start);
            break;
        
        case 2:
            start = display(start);
            break;
        
        case 3:
            start = insert_beg(start);
            break;
        
        case 4:
            start = insert_end(start);
            break;
        
        case 5:
            start = insert_before(start);
            break;
        
        case 6:
            start = insert_after(start);
            break;
        
        case 7:
            start = delete_beg(start);
            break;
        
        case 8:
            start = delete_end(start);
            break;
        
        case 9:
            start = delete_before(start);
            break;
        
        case 10:
            start = delete_after(start);
            break;
        
        case 11:
            start = search_Cll(start);
            break;
        
        case 12:
            start = delete_CLL(start);
            break;
        
        case 13:
            exit(0);
            break;
        
        default:
            printf("\ninvalid choice!!\n");
            break;
        }
    }
    return 0;
}

struct node *create_CLL(struct node *start)
{
    struct node *ptr, *newnode;
    int num;
    printf("\nenter -1 to end\n");
    printf("\nenter the data\n");
    scanf("%d", &num);
    while(num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if(start == NULL)
        {
            newnode->next = newnode;
            start = newnode;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = start;
        }
        printf("\nenter the data:\n");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t",ptr->data);
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *ptr, *newnode;
    int num;
    printf("\nenter the data: \n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = start;
    start = newnode;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *ptr, *newnode;
    int num;
    printf("\nenter the data: \n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = start;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *ptr, *newnode, *preptr;
    int num, val;
    printf("\nenter the data to be inserted: \n");
    scanf("%d", &num);
    printf("\nenter the data before which you want to add the element:\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newnode;
    newnode->next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *ptr, *newnode, *preptr;
    int num, val;
    printf("\nenter the data to be inserted: \n");
    scanf("%d", &num);
    printf("\nenter the data after which you want to add the element:\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    preptr = ptr;
    while(preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newnode;
    newnode->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_before(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nenter the data  before which you want to delete: \n");
    scanf("%d", &val);
    ptr = start;
    while((ptr->next)->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nenter the data  before which you want to delete: \n");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while(preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    if(ptr == start)
    {
        start = ptr->next;
    }
    return start;
}

struct node *search_Cll(struct node *start)
{
    struct node *ptr;
    int num, pos = 1;
    printf("\nenter the number to be searched:\n");
    scanf("%d", &num);
    ptr = start;
    while ((ptr->next != start) && (ptr->data != num))
    {
        ptr = ptr->next;
        pos++;
    }
    printf("\nelement %d is found at position number %d\n", ptr->data, pos);
    return start;
}

struct node *delete_CLL(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != start)
    {
        start = delete_end(start);
    }
    free(ptr);
    return start;
}