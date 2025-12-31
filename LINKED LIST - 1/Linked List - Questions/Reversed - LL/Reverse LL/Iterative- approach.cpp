#include <iostream>
using namespace std; 


//Iterative approach

// template <typename T>
// LinkedListNode<T>* reverseLinkedList(LinkedListNode<T>* head) {
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }

//     LinkedListNode<T>* prev = nullptr;
//     LinkedListNode<T>* curr = head;
//     LinkedListNode<T>* fwd = nullptr;

//     while (curr != nullptr) {
//         fwd = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = fwd;
//     }

//     return prev;
// }

//T.C = O(n)
//S.C = O(1)

// Recursive approach


// void reverse(node* &head, node* curr, node* prev) {

//     //base case
//     if(curr == NULL) {
//         head = prev;
//         return;
//     }

//     node* fwd = curr -> next;
//     reverse(head, fwd, curr);
//     curr -> next =prev;
// }


// node* reverselinked list(node * head) {

//     node* curr = head;
//     node* prev = NULL;
//     reverse(head, curr, prev);
//     return head;
// }


// Better
/* 
node* reverse1(node* head) {
    // base case
    if(head == NULL || head -> == NULL){
     return head;
    }

    node* chotahead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = null;

    return chotahead;
    
    }*/
