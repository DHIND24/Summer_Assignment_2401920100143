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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;//empty tree
        if(root->val==val) return root;//found target node
        if(val<root->val) return searchBST(root->left,val);//target is smaller, search left subtree
        
return searchBST(root->right,val);//target is larger, search right subtree
    }
};
/*
Approach:
- Compare val with the current node value.
- If they are equal -> return the current node.
- If val is smaller -> search in the left subtree.
- If val is greater -> search in the right subtree.
- Continue until the node is found or the tree becomes empty.
Time Complexity: O(h)
- h = height of the BST.
- Balanced BST: O(log n)
- Worst case (skewed BST): O(n)
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
*/