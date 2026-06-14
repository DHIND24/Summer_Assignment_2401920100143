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
 /*Using Tortoise and Hare Method*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    return slow;    
    }
};
/*
Approach:
- Use two pointers: slow and fast.
- Move slow by one node and fast by two nodes.
- When fast reaches the end of the list, slow will be at the middle.
- Return the node pointed to by slow.
Time Complexity: O(n)
- The list is traversed only once.
Space Complexity: O(1)
- Uses only two pointers.
*/
