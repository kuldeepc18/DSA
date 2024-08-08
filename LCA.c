#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree = NULL;

struct node *insertElement(struct node *tree)
{
    int val;
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data of the node : ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL; // Parent of the adding node
        nodeptr = tree;   // For traversing purpose
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

struct node *lowestCommonAncestor(struct node *tree, int node1, int node2)
{
    if (tree == NULL)
        return NULL;
    if (tree->data > node1 && tree->data > node2)
        return lowestCommonAncestor(tree->left, node1, node2);
    if (tree->data < node1 && tree->data < node2)
        return lowestCommonAncestor(tree->right, node1, node2);
    return tree;
}

int count = 0;
struct node *KthSmallestNode(struct node *tree, int k)
{
    if (tree == NULL)
        return NULL;
    struct node *l = KthSmallestNode(tree->left, k);
    if (l != NULL)
        return l;
    count++;
    if (count == k)
        return tree;
    return KthSmallestNode(tree->right, k);
}

int Height(struct node *tree)
{
    int lh, rh;
    if (tree == NULL)
        return 0;
    else
    {
        lh = Height(tree->left);
        rh = Height(tree->right);
        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
}

void checkBalancingCondition(struct node *tree)
{
    int lh, rh;
    if (tree == NULL)
        printf("\nTree is not created yet.");
    else
    {
        lh = Height(tree->left);
        rh = Height(tree->right);
        if (lh == rh + 1 || lh == rh || lh == rh - 1)
            printf("\nTree is balanced");
        else
            printf("\nTree is not balanced");
    }
}

int Print(struct node *tree, int k1, int k2)
{
    if (tree == NULL)
        return 0;
    if (k1 < tree->data)
        Print(tree->left, k1, k2);

    if (k1 <= tree->data && k2 >= tree->data)
        printf("%d ", tree->data);

    Print(tree->right, k1, k2);
}

void main()
{
    int choice;
    printf("*****MENU*****");
    printf("\n1.To insert a node");
    printf("\n2.To find Lowest Common Ancestor");
    printf("\n3.To find the Kth smallest element");
    printf("\n4.To Check whether BST is balanced or not");
    printf("\n5.To print all the elements in the range between k1 and k2");
    printf("\n6.EXIT");
    do
    {
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            tree = insertElement(tree);
            break;
        }
        case 2:
        {
            int node1, node2;
            printf("\nEnter the value of 2 nodes : ");
            scanf("%d%d", &node1, &node2);
            struct node *t = lowestCommonAncestor(tree, node1, node2);
            printf("\nThe LCA of %d and %d is %d",node1,node2,t->data);
            break;
        }
        case 3:
        {
            int k;
            printf("\nEnter the value of k: ");
            scanf("%d", &k);
            struct node *t = KthSmallestNode(tree, k);
            printf("\nKth Smallest element in th bst is : %d", t -> data);
            break;
        }
        case 4:
        {
            checkBalancingCondition(tree);
            break;
        }
        case 5:
        {
            int k1, k2;
            printf("\nEnter the lower limit and upper limit of the range : ");
            scanf("%d%d",&k1,&k2);
            Print(tree,k1,k2);
            break;
        }
        }
    } while (choice != 6);
}