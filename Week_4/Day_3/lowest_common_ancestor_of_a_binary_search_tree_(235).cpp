#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;//empty tree
        if(p->val<root->val && q->val<root->val) return lowestCommonAncestor(root->left,p,q);//both nodes in left subtree
        if(p->val>root->val && q->val>root->val) return lowestCommonAncestor(root->right,p,q);//both nodes in right subtree
        return root;//split occurs here or one node is the root
    }
};
/*
Approach:
- Use the BST property to locate the LCA.
- If both p and q are smaller than the current node, move to the left subtree.
- If both p and q are greater than the current node, move to the right subtree.
- Otherwise, the current node lies between p and q (or equals one of them).
- The current node is the Lowest Common Ancestor.
Time Complexity: O(h)
- h = height of the BST.
- Balanced BST: O(log n)
- Worst case (skewed BST): O(n)
Space Complexity: O(h)
- Recursion stack depth.
*/