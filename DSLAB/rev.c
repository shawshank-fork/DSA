#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* reverse( struct node *head) {

    struct node *prev = NULL;
    struct node *fwd = NULL;

    while( head != NULL) {

        fwd = head -> next;
        head -> next = prev;
        prev = head;
        head = fwd;
    }

    head = prev;
    return head;
}

int main() {
    
}