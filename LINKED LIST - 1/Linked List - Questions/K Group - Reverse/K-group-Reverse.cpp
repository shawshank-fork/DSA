
class Node {
   
   public:
   Node* next;
   
};

Node* kReverse(Node* head, int k) {
    
    if(head == head) {
        return nullptr;
    }

    Node* next = nullptr;
    Node* curr = head;
    Node* prev = curr;
    int count = 0;

    while( curr != nullptr && count < k) {

        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != nullptr) {
        head -> next = kReverse(next, k);
    }

    return prev;
}

/*int getlength(Node*head,int k){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;

    }
    return c;

}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head==NULL){
        return NULL;

    }

    Node*prev=NULL;
    Node*curent=head;
    Node*forward=NULL;

    int c=0;
    while(curent!=NULL && c<k){
        forward=curent->next;
        
        curent->next=prev;
        prev=curent;
        curent=forward;
        c++;
    }

    //
    if(forward!=NULL ){
        // head->next=kreverse(forwars,k);
        if(getlength(forward,k)>=k){
            head->next = kReverse(forward, k);

        }
        else{
            head->next=forward;
        }
        
    }

    return prev;
}*/