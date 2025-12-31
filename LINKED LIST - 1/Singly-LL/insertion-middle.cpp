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

  //destructor
  ~node() {

    int value = this -> data;
    //memory free
    if(this -> next != NULL) {
        delete next;
        this -> next = NULL;
    }
    cout << " memory is free " << value << endl;
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

void insertposition(node* &tail, node* & head, int position, int d ) {

    //insert at start
    if(position == 1) {
        inserthead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

    //inserting at tail
    if(temp -> next == NULL) {
        inserttail(tail, d);
        return;
    }

    //creating a node for d
    node* nodetoinsert = new node(d);

    nodetoinsert -> next = temp -> next;

    temp -> next = nodetoinsert;
}

void dltnode(int position, node* &head) {

    //deleting start node
    if(position == 1) {
        node* temp = head;
        head = head -> next;

        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while( cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
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

    insertposition(tail, head, 4, 22);
    print(head);

    cout << " head " << head -> data << endl;
    cout << " tail " << tail -> data << endl;

    dltnode(3, head);
    print(head);


    return 0;
}