
#include <iostream>
using namespace std; 

class node {
   
   public:
   node* next;
   
};

node* reverse1(node* head) {
    // base case
    if(head == NULL || head -> next == NULL){
     return head;
    }

    node* chotahead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotahead;
    
    }

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