#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*Using Fast and Slow Pointer Method*/
class Solution {
public:
    bool hasCycle(ListNode *head){
        if(!head || !head->next) return false;//empty LL
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast == slow) return true;
        }
    return false;    
    }
};
/*
Approach:
- Use two pointers: slow and fast.
- Move slow by one node and fast by two nodes.
- If a cycle exists, both pointers will eventually meet.
- If fast reaches the end of the list, no cycle exists.
Time Complexity: O(n)
- In the worst case, each node is visited a constant number of times.
Space Complexity: O(1)
- Uses only two pointers.
*/