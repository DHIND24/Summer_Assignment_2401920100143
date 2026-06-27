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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* t1, TreeNode* t2){  
        if(t1==NULL && t2==NULL) return true;//Base case: if both subtrees are empty, they are mirrors
        //if only one is empty, or the values don't match, they aren't symmetric
        if(t1==NULL || t2==NULL || t1->val != t2->val) return false;
        //recursively check outer pairs (t1->left, t2->right) and inner pairs (t1->right, t2->left)
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }   
};
/*
Approach:
- Check whether the left and right subtrees are mirror images of each other.
- If both nodes are NULL, they are symmetric.
- If only one node is NULL or their values differ, the tree is not symmetric.
- Recursively compare:
  - Left child of the first subtree with the right child of the second subtree.
  - Right child of the first subtree with the left child of the second subtree.
- If all corresponding pairs match, the tree is symmetric.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
- Balanced tree: O(log n)
- Skewed tree: O(n)
*/