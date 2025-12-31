#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



class Solution {
    public:
    
        ListNode* rev(ListNode* head) {
            ListNode* temp = head;
            ListNode* prev = NULL;
    
            while(temp != NULL) {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            return prev;
        }
    
        ListNode* getknode(ListNode* temp, int k) {
            k -= 1;
            while(temp != NULL && k > 0) {
                k--;
                temp = temp -> next;
            }
            return temp;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
    
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp != NULL) {
                ListNode* knode = getknode(temp, k);
                if(knode == NULL) {
                    if(prev) prev->next = temp;
                    break;
                }
    
                    ListNode* nextnode = knode->next;
                    knode->next = NULL;
                    rev(temp);
                    if(temp == head){
                    head = knode;
                }else {
                    prev->next = knode;
                }
    
                prev = temp;
                temp = nextnode;
           } 
           return head;
        }
    };