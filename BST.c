#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *tree;

void create_tree(struct node *tree);
struct node *insert_element(struct node *tree);
void preorderTraversal(struct node *tree);
void inorderTraversal(struct node *tree);
void postorderTraversal(struct node *tree);
struct node *find_smallest_element(struct node *tree);
struct node *find_largest_element(struct node *tree);
struct node *delete_element(struct node *tree, int num);
struct node *mirror_tree(struct node *tree);
int total_nodes(struct node *tree);
int total_external_nodes(struct node *tree);
int total_internal_nodes(struct node *tree);
int height(struct node *tree);
struct node *delete_tree(struct node *tree);

int main()
{
    int choice, num;
    struct node *ptr;
    create_tree(tree);
    while (1)
    {
        printf("\n***Main Menu***\n");
        printf("\n1. create the tree");
        printf("\n2. insert element in the tree");
        printf("\n3. preorder traversal");
        printf("\n4. inorder traversal");
        printf("\n5. postorder traversal");
        printf("\n6. find the smallest element");
        printf("\n7. find the largest element");
        printf("\n8. delete the element");
        printf("\n9. mirror the whole tree");
        printf("\n10. count total number of nodes");
        printf("\n11. count total number of external nodes");
        printf("\n12. count total number of internal nodes");
        printf("\n13. calculate height of the tree");
        printf("\n14. delete the ehole tree");
        printf("\n15. exit");
        printf("\nenter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_tree(tree);
            break;

        case 2:
            tree = insert_element(tree);
            break;

        case 3:
            printf("the elements of tree in using Preorder traversal is: \n");
            preorderTraversal(tree);
            break;

        case 4:
            printf("the elements of tree in using Inorder traversal is: \n");
            inorderTraversal(tree);
            break;

        case 5:
            printf("the elements of tree in using Postorder traversal is: \n");
            postorderTraversal(tree);
            break;

        case 6:
            ptr = find_smallest_element(tree);
            printf("\nsmallest element is: %d\n", ptr->data);
            break;

        case 7:
            ptr = find_largest_element(tree);
            printf("\nlargest element is: %d\n", ptr->data);
            break;

        case 8:
            printf("\nenter the data to be deleted for the tree: \n");
            scanf("%d", &num);
            tree = delete_element(tree, num);
            break;

        case 9:
            tree = mirror_tree(tree);
            break;

        case 10:
            printf("\ntotal number of nodes in the tree are: %d\n", total_nodes(tree));
            break;

        case 11:
            printf("\ntotal number of external nodes in the tree are: %d\n", total_external_nodes(tree));
            break;

        case 12:
            printf("\ntotal number of internal nodes in the treee are: %d\n", total_internal_nodes(tree));
            break;

        case 13:
            printf("\nheight of the tree is :%d\n", height(tree));
            break;

        case 14:
            tree = delete_tree(tree);
            break;

        case 15:
            exit(0);
            break;

        default:
            printf("\ninvalid choice!!\n");
            break;
        }
    }
    return 0;
}

void create_tree(struct node *tree)
{
    tree = NULL;
}

struct node *insert_element(struct node *tree)
{
    struct node *ptr, *nodeptr, *parentptr;
    int num;
    printf("\nentr the data to be inserted: \n");
    scanf("%d", &num);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
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
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (num < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (num < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

void preorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

struct node *find_smallest_element(struct node *tree)
{
    if (tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        find_smallest_element(tree->left);
    }
}

struct node *find_largest_element(struct node *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        find_largest_element(tree->right);
    }
}

struct node *delete_element(struct node *tree, int num)
{
    struct node *temp;
    if (tree == NULL)
    {
        printf("\nvalue not found in the tree!!\n");
    }
    else if (num < tree->data)
    {
        tree->left = delete_element(tree->left, num);
    }
    else if (num > tree->data)
    {
        tree->right = delete_element(tree->right, num);
    }
    else
    {
        if (tree->left && tree->right)
        {
            temp = find_largest_element(tree->left);
            tree->data = temp->data;
            tree->left = delete_element(tree->left, temp->data);
        }
        else
        {
            temp = tree;
            if (tree->left == NULL)
            {
                tree = tree->right;
            }
            else if (tree->right == NULL)
            {
                tree = tree->left;
            }
        }
        free(temp);
    }
    return tree;
}

struct node *mirror_tree(struct node *tree)
{
    struct node *ptr;
    if (tree != NULL)
    {
        mirror_tree(tree->left);
        mirror_tree(tree->right);
        ptr = tree->left;
        tree->left = tree->right;
        tree->right = ptr;
    }
}

int total_nodes(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (total_nodes(tree->left) + total_nodes(tree->right) + 1);
    }
}

int total_external_nodes(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return (total_external_nodes(tree->left) + total_external_nodes(tree->right));
    }
}

int total_internal_nodes(struct node *tree)
{
    if ((tree == NULL) || (tree->left == NULL && tree->right == NULL))
    {
        return 0;
    }
    else
    {
        return (total_internal_nodes(tree->left) + total_internal_nodes(tree->right) + 1);
    }
}

int height(struct node *tree)
{
    int leftheight, rightheight;
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        leftheight = height(tree->left);
        rightheight = height(tree->right);
        if (leftheight > rightheight)
        {
            return (leftheight + 1);
        }
        else
        {
            return (rightheight + 1);
        }
    }
}

struct node *delete_tree(struct node *tree)
{
    if (tree != NULL)
    {
        delete_tree(tree->left);
        delete_tree(tree->right);
        free(tree);
    }
}