#include<bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL; //case: empty list
        ListNode* curr = head;//Current node to process
        ListNode* back = NULL;//Previous node or new next pointer
        ListNode* temp = NULL;//Temporary storage for next node
        while(curr != NULL){
            temp=curr->next;//Save next node
            curr->next=back;//Reverse current node's pointer
            back=curr;//Move back pointer forward
            curr=temp;//Move curr pointer forward
        }
    return back;//back is new head
    }
};
/*
Approach:
- Traverse the linked list using a current pointer.
- Store the next node before changing any links.
- Reverse the current node's next pointer.
- Move both current and previous pointers forward.
- Continue until all nodes are reversed.
- Return the new head of the reversed list.
Time Complexity: O(n)
- Each node is visited exactly once.
Space Complexity: O(1)
- Reversal is performed using a few pointers.
*/