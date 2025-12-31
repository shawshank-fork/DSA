#include <stdio.h>
#include <stdlib.h>
typedef struct node

{
    int data;
    struct node *next;

}NODE;

void insert(NODE **front, NODE **rear)

{
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    printf("Enter the element: ");
    scanf("%d",&ptr->data);
    if((*front) == NULL)
    
    {
        ptr->next = ptr;
        *front = *rear = ptr;
    }


    else

    {
        ptr->next = *front;
        (*rear)->next = ptr;
        *rear = ptr;
    }    
}

void delete(NODE **front, NODE **rear)

{
    if((*front) == NULL)
    printf("Queue is Empty \n");
    else
    {
        printf("Deleted Element: %d \n",(*front)->data);
        if(*front == *rear)
        *front = *rear = NULL;
        else
        {
            NODE *temp = *front;
            *front = (*front)->next;
            (*rear)->next = *front;
            free(temp);
        }
    }
}

void display(NODE **front)

{
    if((*front) == NULL)
    printf("Queue is Empty \n");
    else
    {   
        NODE *ptr = *front;
        printf("The Elements are: ");
        while(ptr->next != (*front))
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d \n",ptr->data);
    }
}

int main()

{
    int b = 1,c;
    NODE *top = NULL;
    NODE *rear = NULL;
    while(b)
    {
        printf("1.Insert \n2.Delete \n3.Traverse \n4.Exit \n");
        printf("Enter your Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert(&top,&rear);
            break;
            case 2:
            delete(&top,&rear);
            break;
            case 3:
            display(&top);
            break;
            case 4:
            b = 0;
            continue;
            default:
            printf("Wrong Input \n");
        }
    }

    return 0;
}