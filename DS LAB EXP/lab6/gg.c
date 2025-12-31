#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int j = -1;
char ch1[100];
typedef struct node

{
    char data;

    struct node *next;

}NODE;

void pop(NODE **top, char c);

int pre(char c)

{
    switch(c)

    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
    }

    return 0;
}

void push(NODE **top, char c)

{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = c;

    if((*top) == NULL)

    temp->next = NULL;

    else

    {
        if((pre(c) > pre((*top)->data)) || c == ')')
        temp->next = *top;
        else

        {
            while(pre(c) < pre((*top)->data))
            pop(&(*top),c);
            temp->next = *top;
        }
    }

    *top = temp;
}

void pop(NODE **top, char c)
{
    if(c == '(')

    {
        NODE *temp;

        while((*top)->data != ')')

        {
            temp = *top;
            ch1[++j] = temp->data;
            (*top) = (*top)->next;
            free(temp);
        }

        temp = *top;

        (*top) = (*top)->next;

        free(temp);
    }

    else

    {
        ch1[++j] = (*top)->data;
        *top = (*top)->next;
    }
}

void rev(int j)

{
    for(int i = (j-1); i >=0; i--)

    printf("%c",ch1[i]);
    printf("\n");
}

int main()
{

    int i,l;

    char ch[100];

    printf("Enter an Infix Expression without spaces: ");
    scanf("%s",ch);

    l = strlen(ch);
    ch[l] = '\n';

    NODE *top = NULL;
    push(&top,')');

    for(i = (l-1); i >= 0; i--)

    {
        int a = (int)(ch[i]);
        if((a >= 65) && (a <= 90) || (a >= 97) && (a <= 122) || (a >= 48) && (a <= 57))
        ch1[++j] = ch[i];
        else if(ch[i] == ')' || ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '^')
        push(&top,ch[i]);
        else if(ch[i] == '(')
        pop(&top,ch[i]);
    }
    
    pop(&top,'(');
    ch1[++j] = '\n';
    rev(j);
    return 0;
}
