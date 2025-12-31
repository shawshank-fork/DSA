#include <iostream>
using namespace std; 

class node {
  
  public:
  int data;
  node* next;

  //constructor

  node(int data) {
    this->data = data;
    this->next = NULL;
  }

};

void inserthead(node* &head, int d) {
    
    //creating new node
   node* temp = new node(d);
   temp -> next = head;
   head = temp;

}

void inserttail(node* &tail, int d) {

    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;

}

void print(node* &head) {
     node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    
    node* node1 = new node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl; 

    node* head = node1;
    node* tail = node1;
    print(head);
    
   //inserthead(head, 12)

    inserttail(tail,12);
    print(head);

    inserttail(tail, 15);
    print(head);


    return 0;
}