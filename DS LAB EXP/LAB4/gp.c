#include <stdio.h>
#include <stdlib.h>

struct node {

int data;

struct node* next;
struct node* prev;

};

struct node* createnode( int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode -> data = data;
    newnode-> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

void displaylist( struct node* head) {
     if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    struct node* temp = head;
    printf(" list is : ");
    while(temp != NULL) {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    printf("\n")
}

void displaylistreverse(struct node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

     struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List in reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}

int main() {

struct node* head = NULL;
int position, data, choice;
char cont;

printf(" enter the elements: ");
while( scanf("%d", &data)) {

    head = insertatend(head, data);
    if(getchar() == '\n') break;
}

do {
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Display the list in reverse order\n");
        printf("4. Insert the element at beginning\n");
        printf("5. Insert the element at the end\n");
        printf("6. Insert the element at a specific position\n");
        printf("7. Delete the element from the beginning\n");
        printf("8. Delete the element from the end\n");
        printf("9. Delete the element from a specific position\n");
        printf("10. Count the total number of nodes\n");
        printf("11. Search an element in the linked list\n");
        printf("12. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        }
 }





    return 0;
}   