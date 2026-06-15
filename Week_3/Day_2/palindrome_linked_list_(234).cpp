/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    return prev;    
    }
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL) return true;//edge case : 
        //find middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);//reverse the LL from the middle element
        ListNode* first=head;//first pointer for comparison
        ListNode* second=newHead;//second pointer for comparison
        while(second != NULL){//treverse the reversed list
            if(first->val != second->val){// check each node
                reverse(newHead);//if condition gets true : undo reversal
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);// undo reversal
    return true;
    }
};
/*
Approach:
- Find the middle node of the linked list using slow and fast pointers.
- Reverse the second half of the linked list.
- Compare nodes from the first half and the reversed second half.
- If any pair of nodes differs -> return false.
- Restore the original linked list by reversing the second half again.
- If all corresponding nodes match -> return true.
Time Complexity: O(n)
- One traversal to find the middle, one to reverse, and one to compare.
Space Complexity: O(1)
- Uses only a few pointers.
*/