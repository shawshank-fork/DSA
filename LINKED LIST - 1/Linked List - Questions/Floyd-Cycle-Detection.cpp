#include <iostream>
using namespace std; 

class Node {
   
   public:
   Node* next;
   
};

Node* floyd(Node* head) {

    if(head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while( slow != NULL && fast != NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << " present at slow -> data " << endl;
            return slow;
        }
    }

    return NULL;
}

int main() {

    // if(floyd(head) != NULL) {
    //     cout << " cycle is present " << endl;
    // }
    // else {
    //     cout << " no cycle " << endl;
    // }
}