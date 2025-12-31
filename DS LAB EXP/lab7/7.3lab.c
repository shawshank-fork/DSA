#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1,s = 0;
void insert(int *arr, int max)
{
    if(s == max)
    {
        printf("Queue is Full \n"); 
        return;
    }
    rear++;
    if(rear == max)
    rear = 0;
    if(front == -1)
    front++;
    printf("Enter the element: ");
    scanf("%d",&arr[rear]);
    s++;
    
}
void delete(int *arr, int max)
{
    if(front == -1)
    printf("Queue is Empty \n");
    else
    {
        printf("Deleted Element: %d \n",arr[front]);
        s--;
        if(front == rear)
        front = rear = -1;
        else
        front++;
        if(front == max)
        front = 0;
    }
}
void display(int *arr, int max)
{
    if(front == -1)
    printf("Queue is Empty \n");
    else
    {   int j = front;
        printf("The Elements are: ");
        for(int i = 0; i < s; i++)
        {
            printf("%d ",arr[j++]);
            if(j == max)
            j = j % max;
        }
        printf("\n");
    }
}
int main()
{
    int b = 1,c,max;
    printf("Enter the size: ");
    scanf("%d",&max);
    int *arr = (int *)malloc(max*sizeof(int));
    while(b)
    {
        printf("1.Insert \n2.Delete \n3.Traverse \n4.Exit \n");
        printf("Enter your Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert(arr,max);
            break;
            case 2:
            delete(arr,max);
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