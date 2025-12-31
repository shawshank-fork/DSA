#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
void insert(int *arr, int max)

{
    if(rear == (max-1))
    {
        printf("Queue is Full \n");
        return;
    }
    else 
    {
        if(front == -1)
        ++front;
        printf("Enter the element: ");
        scanf("%d",&arr[++rear]);
    }
}
void delete(int *arr)
{
    if((front == -1))
    printf("Queue is Empty \n");
    else
    {
        printf("Deleted Element: %d \n",arr[front]);
        if(front == rear)
        front = rear = -1;
        else
        ++front;
    }
}
void display(int *arr, int max)
{
    if((front == -1))
    {
        printf("Queue is Empty \n");
        return;
    }
    printf("The Elements are: ");
    for(int i = front; i <= rear; i++)
    printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int b = 1,c,max;
    printf("Enter the size: ");
    scanf("%d",&max);
    int *arr = (int *)malloc(max*sizeof(int));
    while(b)
    {
        printf("1.Add \n2.Delete \n3.Traverse \n4.Exit \n");
        printf("Enter your Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert(arr,max);
            break;
            case 2:
            delete(arr);
            break;
            case 3:
            display(arr,max);
            break;
            case 4:
            b = 0;       
            
            continue;
            default:
            printf("Wrong Input \n");
        }
    }
    free(arr);
    return 0;
}