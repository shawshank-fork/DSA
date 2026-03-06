#include<iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
    public:
        // Merges two sorted linked lists
        ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
            ListNode* dummyNode = new ListNode(-1);
            ListNode* temp = dummyNode;
    
            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    temp->next = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    list2 = list2->next;
                }
                temp = temp->next;
            }
    
            if (list1) temp->next = list1;
            else temp->next = list2;
    
            return dummyNode->next;
        }
    
        // Sorts the linked list using merge sort
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head;
    
            // Step 1: Find the middle of the list
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Step 2: Split the list into two halves
            ListNode* mid = slow->next;
            slow->next = nullptr;
    
            // Step 3: Recursively sort both halves
            ListNode* left = sortList(head);
            ListNode* right = sortList(mid);
    
            // Step 4: Merge the sorted halves
            return mergeTwoSortedLinkedLists(left, right);
        }
    };