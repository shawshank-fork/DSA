#include <iostream>
using namespace std; 

class node {

    public:
    int data;
    node* prev;
    node* next;

    //constructor
    node(int d) {

        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;

    }

    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(node* head) {
    
    node* temp = head;

    while( temp != NULL) {
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

// int len(node* head) {
//     int len = 0;
//     node* temp = head;

//     while(temp != NULL) {
//         len++;
//         temp = temp -> next;
//     }

//     return len;
// }

void inserthead( node* &tail, node* &head, int d) {
    
    //empty list
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }

    else{
        
        node* temp = new node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void inserttail(node* &tail, node* &head, int d) {
    
     if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }

    else{
        node* temp = new node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
  
}

void insertpos(node* &tail, node* &head, int position, int d) {

       //insert at start
    if(position == 1) {
        inserthead(tail, head, d);
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
        inserttail(tail, head, d);
        return;
    }

    //creating a node for d
    node* nodetoinsert = new node(d);

    nodetoinsert -> next = temp -> next;

    temp -> next -> prev = nodetoinsert;

    temp -> next = nodetoinsert;

    nodetoinsert -> prev = temp;

}

void dltnode(int position, node* &head) {

    //deleting start node
    if(position == 1) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;

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

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }
}

int main() {

    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);

    // cout  << " length - " << len(head) << endl;

    inserthead(tail, head, 13);
    print(head);

    inserthead(tail, head, 11);
    print(head);

    inserttail(tail, head, 25);
    print(head);

    inserttail(tail, head, 45);
    print(head);

    insertpos(tail, head, 1, 101);
    print(head);

   insertpos(tail, head, 2, 100);
   print(head);

   dltnode(1, head);
   print(head);





    return 0;
}