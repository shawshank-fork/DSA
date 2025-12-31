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

void displaylist(struct node* head) {

    if(head == NULL) {
        printf("empty list\n");
        return;
    }
    struct node* temp = head;
    printf(" list is: ");
    while(temp != NULL) {
        printf( "%d", temp -> data);
        temp = temp -> next;
    }
    printf("n");
}

struct node* inserthead(struct node* head, int data) {
    struct node* newnode = createnode(data);
    newnode -> next = head;
    return newnode;
}

struct node* insertatend(struct node* head, int data) {
    struct node* newnode = createnode(data);
    if(head == NULL) {
        return newnode;
    }

    struct node* temp = head;

    while( temp != NULL) {
        temp = temp -> next;
    }

    temp -> next = newnode;
    return head;
    
}

struct node* insertatposition( struct node* head, int data, int position) {

    struct node* newnode = createnode(data);

    if(position == 1) {
        newnode -> next = head;
        return newnode;
    }

    struct node* temp = head;
    for( int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp -> next;
    }

    if(temp == NULL) {
        printf(" position out of range \n");
        return head;
    }

    newnode -> next = temp -> next;
    temp -> next = newnode;
    return head;
}

struct node* deletefromstart(struct node* head) {

    if( head == NULL) {
        printf(" list is empty \n");
        return head;
    }

    struct node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}

struct node* deletefromend( struct node* head) {

     if( head == NULL) {
        printf(" list is empty \n");
        return head;
    }

    if( head -> next = NULL){
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
    return head;

}

struct node* deletefromposition( struct node* head, int position) {

     if( head == NULL) {
        printf(" list is empty \n");
        return head;
    }

    if(position == 1) {

        struct node* temp = head;
        head = head -> next;
        free(temp);
        return head;

    }

    struct node* temp = head;
    for( int i = 1; i < position -1 && temp != NULL; i++) {
        temp = temp -> next;
    }

    if( temp == NULL || temp -> next == NULL) {

        printf(" position out of range\n " );
        return head;
    }

    struct node* next = temp -> next -> next;
    free(temp -> next);
    temp -> next = next;
    return head;
}

int countnodes( struct node* head) {
    int count = 0;
    struct node* temp = head;
    while( temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

int search( struct node* head, int key) {

    struct node* temp = head;
    int position= 1;
    while( temp != NULL) {

        if(temp -> data == key)
        return position;
        temp = temp -> next;
        position++;
    }
    return -1;
}


int main(){

struct node* head = NULL;    
int data, choice, position;
char cont;

 printf("Enter the elements: ");
    while (scanf("%d", &data)) {

        head = insertatend(head, data);
        if (getchar() == '\n') break; 
        
    }

    do {
        printf("1. create a node\n");
        printf("2. Display the list\n");
        printf("3. Insert the element at beginning\n");
        printf("4.Insert the element at the end\n");
        printf("5.Insert the element at specific position\n");
        printf("6.Delete the element from the beginning\n");
        printf("7.Delete the element from the end\n");
        printf("8.Delete the element from specific position\n");
        printf("9.Count the total number of nodes\n");
        printf("10.Search an element in the linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
            printf("enter the value to insert: ");
            while (scanf("%d", &data )) {
               head = insertatend(head, data);
               if (getchar() == '\n') break;
            }
            break;

            case 2:
            displaylist(head);
            break;

            case 3:
            printf("enter the value to insert: ");
            scanf("%d", &data);
            head = inserthead(head, data);
            break;

            case 4:
            printf("enter the value to insert: ");
            scanf("%d", &data);
            head = insertatend(head, data);
            break;

            case 5:
            printf("enter the value to insert: ");
            scanf("%d", &data);
            printf(" enter the position to insert the value at: ");
            scanf("%d", &position);
            insertatposition(head, data, position);
            break;

            case 6:
            head = deletefromstart(head);
            break;

            case 7:
            head = deletefromend(head);
            break;
            

            case 8:
            printf("enter position to dlt: ");
            scanf("%d", &position);
            head = deletefromposition(head, position);
            break;

            case 9:
            printf(" totoal number of nodes: %d\n", countnodes(head));
            break;

            case 10:
            printf(" enter elemnt to search: ");
            scanf("%d", &data);
            position = search(head, data);
             if (position != -1)
                    printf("Element found at position %d\n", position);
                else
                    printf("Element not found\n");
            break;

            case 11:
            printf("exiting \n");
            break;

            default:
            printf(" invalid choice. \n"); 

        }  

        if (choice != 11) {
            printf("Do you want to Continue (Y/N): ");
            scanf(" %c", &cont);
            if (cont == 'N' || cont == 'n') {
                break;
            }
       }
   } while (choice != 11);

   return 0;

}

