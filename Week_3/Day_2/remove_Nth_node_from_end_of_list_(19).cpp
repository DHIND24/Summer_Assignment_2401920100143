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
    int countNodes(ListNode* head){// to count the number of nodes
        int count=0;
        ListNode* temp = head;
        while(temp !=NULL){
            count++;
            temp = temp->next;
        }
    return count;    
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int pos = countNodes(head)-n;
        if(pos == 0){//edge case : if the node to be deleted is head 
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(pos > 1){// normal cases
            temp = temp->next;
            pos--;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);
    return head;    
    }
};
/*
Approach:
- Count the total number of nodes in the linked list.
- Find the position of the node to be removed from the beginning.
- If the head node needs to be removed, update the head pointer.
- Otherwise, move to the node just before the target node.
- Delete the target node and reconnect the list.
- Return the updated head.
Time Complexity: O(n)
- One traversal for counting nodes and another traversal for deletion.
Space Complexity: O(1)
- Uses only a few pointers and variables.
*/
