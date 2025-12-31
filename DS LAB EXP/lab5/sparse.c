
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
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
        ptr->next = temp;
    }
}
void display(NODE *head, int r, int c)
{
    NODE *ptr = head;
    int a = 0;
    for(int i = 1; i <= (r*c); i++)
    {
        if(ptr->data != 0)
        a++;
        ptr = ptr->next;
    }
    printf("Sparse Matrix in 3-tuple format: \n");
    printf("Row \tColumn \tValue \n");
    printf("%d \t%d \t%d \n",r,c,a);
    ptr = head;
    for(int i = 1; i <= (r*c); i++)
    {
        int n, m = (i % c) - 1;
        if((((double)i)/c) > (double)(i/c))
        n = i/c;
        else
        {
            n = (i/c) - 1;
            m = c - 1;
        }
        if(ptr->data != 0)
        printf("%d \t%d \t%d \n",n,m,ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int r,c,d;
    NODE *head = NULL;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d",&r,&c);
    if(r == 0 || c == 0)
    {
        printf("Wrong Size \n");
        return 0;
    }
    printf("Enter elements of the sparse matrix: ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d",&d);
            input(&head,d);
        }
    }
    display(head,r,c);
    return 0;
}