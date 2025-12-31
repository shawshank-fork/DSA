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

Node* getstartingNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floyd(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

int main() {

    // if(floyd(head) != NULL) {
    //     cout << " cycle is present " << endl;
    // }
    // else {
    //     cout << " no cycle " << endl;
    // }

    // Node* loop = getstartingNode(head);

    // cout << " loop starts at " << loop -> data << endl;
}