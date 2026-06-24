#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root,long long low,long long high){
        if(root==NULL) return true;//empty tree is a valid BST
        if(root->val<=low || root->val>=high) return false;//value violates BST property
        return check(root->left,low,root->val) && check(root->right,root->val,high);//check left and right subtrees
    }
    bool isValidBST(TreeNode* root){
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};
/*
Approach:
- For every node, maintain the valid range of values it can take.
- Initially, the root can have any value.
- For the left child, the upper bound becomes the current node value.
- For the right child, the lower bound becomes the current node value.
- If any node violates its valid range, return false.
- If all nodes satisfy the BST property, return true.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
- Balanced BST: O(log n)
- Worst case (skewed tree): O(n)
*/