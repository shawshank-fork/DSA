#include <iostream>
using namespace std; 

class node {
   
   public:
   node* next;
   
};

void reverse(node* &head, node* curr, node* prev) {

    //base case
    if(curr == NULL) {
        head = prev;
        return;
    }

    node* fwd = curr -> next;
    reverse(head, fwd, curr);
    curr -> next =prev;
}


node* reverselinkedlist(node * head) {

    node* curr = head;
    node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}
