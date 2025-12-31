#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;
void input(NODE **head, int a)
{
    NODE *ptr = *head;
    if(ptr == NULL)
    {
        ptr = (NODE *)malloc(sizeof(NODE));
        ptr->data = a;
        ptr->prev = ptr;
        ptr->next = ptr;
        *head = ptr;
    }
    else
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        while(ptr->next != (*head))
        ptr = ptr->next;
        temp->data = a;
        temp->next = *head;
        temp->prev = ptr;
        ptr->next = temp;
        (*head)->prev = temp;
    }
}
void display(NODE *head)
{
    NODE *ptr = head;
    if(ptr == NULL)
    printf("List is empty. \n");
    else
    {
        printf("The Elements are: ");
        while(ptr->next != head)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d \n",ptr->data);
    }
}
int main()
{
    int n,d;
    NODE *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        printf("Enter the element at node %d: ",i);
        scanf("%d",&d);
        input(&head,d);
    }
    display(head);
    return 0;
}