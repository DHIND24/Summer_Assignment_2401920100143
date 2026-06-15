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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //edge case : if one list is empty, return the other directly
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head = NULL;
        if(list1->val <= list2->val){//decide the head of merged list
            head = list1;
            list1 = list1->next; //move list1 forward
        }
        else{
            head = list2;
            list2 = list2->next; //move list2 forward
        }
        ListNode* curr = head;//pointer to build merged list
        while(list1 && list2){//traverse both lists and attach smaller node each time
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;//move current pointer forward
        }
        curr->next = list1 ? list1 : list2;//attach remaining nodes (only one list will be non-empty)
return head;
    }
};
/*
Approach:
- Handle edge cases where one of the lists is empty.
- Choose the smaller first node as the head of the merged list.
- Traverse both lists simultaneously.
- Attach the smaller node to the merged list and move its pointer forward.
- After one list is exhausted, attach the remaining nodes of the other list.
- Return the head of the merged list.
Time Complexity: O(list1.size() + list2.size())
- Each node from both lists is visited exactly once.
Space Complexity: O(1)
- Merging is performed using existing nodes without extra space.
*/