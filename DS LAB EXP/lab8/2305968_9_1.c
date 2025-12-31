#include <stdio.h>
#include <stdlib.h>
int h = 0, max = 0;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
NODE *create(NODE *root, int a)
{
    root = (NODE*)malloc(sizeof(NODE));
    root->data = a;
    root->left = NULL;
    root->right = NULL;
    return root;
}
NODE *insert(NODE *root, int a)
{
    h++;
    if(root == NULL)
    return create(root,a);
    else if(root->data > a)
    root->left = insert(root->left,a);
    else if(root->data < a)
    root->right = insert(root->right,a);
    return root;
}
void pre(NODE *root)
{
    if(root == NULL)
    return;
    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}
void in(NODE *root) 
{
    if (root == NULL) 
    return;
    in(root->left);
    printf("%d ", root->data);
    in(root->right);
}
void post(NODE *root) 
{
    if (root == NULL)
    return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}
int large(NODE *root)
{
    if(root->right == NULL)
    return root->data;
    return large(root->right);
}
int small(NODE *root)
{
    if(root->left == NULL)
    return root->data;
    return small(root->left);
}
NODE *delete(NODE *root, int a)
{
    if(root == NULL)
    {
        printf("Element Not Found \n");
        return root;
    }
    if(a < root->data)
    root->left = delete(root->left,a);
    else if(a > root->data)
    root->right = delete(root->right,a);
    else
    {
        if(root->left == NULL)
        return root->right;
        else if(root->right == NULL)
        return root->left;
        root->data = large(root->left);
        root->left = delete(root->left,root->data);
    }
    return root;
}
int main()
{
    int b = 1,c,a,con = 0;
    NODE *root = NULL;
    while(b)
    {
        printf("1.Insert in node in BST \n");
        printf("2.Display (preorder) in BST \n");
        printf("3.Display (inorder) in BST \n");
        printf("4.Display (postorder) in BST \n");
        printf("5.Find largest element \n");
        printf("6.Find smallest element \n");
        printf("7.Delete the element \n");
        printf("8.No. of Nodes \n");
        printf("9.Height of Tree \n");
        printf("10.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        if(c > 1 && c < 9 && root == NULL)
        {
            printf("Binary Tree is Empty \n");
            continue;
        }
        switch(c)
        {
            case 1:
            printf("Enter the element: ");
            scanf("%d",&a);
            con++;
            root = insert(root,a);
            if(h > max)
            max = h;
            h = 0;
            break;
            case 2:
            printf("The Elements in Preorder are: ");
            pre(root);
            printf("\n");
            break;
            case 3:
            printf("The Elements in Inorder are: ");
            in(root);
            printf("\n");
            break;
            case 4:
            printf("The Elements in Postorder are: ");
            post(root);
            printf("\n");
            break;
            case 5:
            printf("Largest Number: %d \n",large(root));
            break;
            case 6:
            printf("Smallest Number: %d \n",small(root));
            break;
            case 7:
            printf("Enter the element to be deleted: ");
            scanf("%d",&a);
            root = delete(root,a);
            break;
            case 8:
            printf("No. of Nodes = %d \n",con);
            break;
            case 9:
            printf("Height = %d \n",max);
            break;
            case 10:
            return 0;
            default:
            printf("Wrong Input \n");
        }
    }
    return 0;
}