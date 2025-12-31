#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* next;
    
};

struct node* createnode(int data) {

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int data;

    if ( n <= 0) {

        printf(" invalid number of nodes \n");
        return NULL;
    }

    for ( int i = 1; i <= n; i++) {

        printf( " enter info of nodes %d: ", i);
        scanf( "%d", &data);
        newnode = createnode(data);

        if (head == NULL) {

            head = newnode;

        } else {

            temp -> next = newnode;

        }
        temp = newnode;
    }

    temp -> next = head;

    return head;

}

void cll( struct node* head) {

    struct node* temp = head;

    if( head == NULL) {
        printf( " the list is empty \n ");
        return;
    }

    printf( " circular linekd list: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
    
}

int main() {

    struct node* head = NULL;
    int n;

    printf(" enter no. of nodes: ");
    scanf("%d", &n);

    head = create(n);

    cll(head);

    return 0;

}
