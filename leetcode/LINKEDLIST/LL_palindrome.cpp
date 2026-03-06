#include<iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;
    
            // Step 1: Find the middle (slow will point to middle)
            ListNode *slow = head, *fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Step 2: Reverse second half
            ListNode* prev = nullptr;
            while (slow) {
                ListNode* temp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = temp;
            }
    
            // Step 3: Compare both halves
            ListNode* left = head;
            ListNode* right = prev;  // start of reversed second half
            while (right) {
                if (left->val != right->val)
                    return false;
                left = left->next;
                right = right->next;
            }
    
            return true;
        }
    };


    ListNode* reverse(ListNode *head){
        if(head == NULL || head -> next == NULL) return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
class Solution { 
public:
    bool isPalindrome(ListNode* head) {
        
       if(head == NULL || head->next == NULL) return true;
       ListNode* slow = head;
       ListNode* fast = head;

       while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow -> next;
        fast = fast->next->next;
       } 

       ListNode* newhead = reverse(slow->next);
       ListNode* first = head;
       ListNode* second = newhead;
       while(second != NULL) {
            if(first->val != second->val) {
                reverse(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
       }
       reverse(newhead);
       return true;
    }

}   