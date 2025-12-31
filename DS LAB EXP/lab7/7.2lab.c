#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
int isEmpty(NODE *front, NODE *rear)
{
    if(front == NULL && rear == NULL)
    return 1;
    return 0;
}
void insert(NODE **front, NODE **rear, int a)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    printf("Enter the element: ");
    scanf("%d",&ptr->data);
    ptr->next = NULL;
    if(isEmpty(*front,*rear))
    *front = *rear = ptr;
    else if(a == 1)
    {
        ptr->next = *front;
        *front = ptr;
    }
    else if(a == 2)
    {
        (*rear)->next = ptr;
        *rear = ptr;
    }
}
void delete(NODE **front, NODE **rear, int a)
{
    if(isEmpty(*front,*rear))
    printf("Queue is Empty \n");
    else if(a == 1)
    {
        NODE *temp = *front;
        printf("Deleted Element: %d \n",temp->data);
        if(*front == *rear)
        *front = *rear = NULL;
        else
        *front = (*front)->next;
        free(temp);
    }
    else if(a == 2)
    {
        NODE *temp = *rear;
        printf("Deleted Element: %d \n",temp->data);
        if(*front == *rear)
        *front = *rear = NULL;
        else
        {
            temp = *front;
            while(temp->next != *rear)
            temp = temp->next;
            *rear = temp;
            temp = temp->next;
            (*rear)->next = NULL;
        }
        free(temp);
    }
}
void display(NODE *front, NODE *rear)
{
    if(isEmpty(front,rear))
    printf("Queue is Empty \n");
    else
    {
        NODE *ptr = front;
        printf("The Elements are: ");
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    int b = 1,c;
    NODE *front = NULL, *rear = NULL;
    while(b)
    {
        printf("1.Insert at front end \n");
        printf("2.Insert at rear end \n");
        printf("3.Delete at front end \n");
        printf("4.Delete at rear end \n");
        printf("5.Display \n");
        printf("6.Exit \n");
        printf("Enter your Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert(&front,&rear,1);
            break;
            case 2:
            insert(&front,&rear,2);
            break;
            case 3:
            delete(&front,&rear,1);
            break;
            case 4:
            delete(&front,&rear,2);
            break;
            case 5:
            display(front,rear);
            break;
            case 6:
            b = 0;
            continue;
            default:
            printf("Wrong Input \n");
        }
    }
    free(front);
    free(rear);
    return 0;
}