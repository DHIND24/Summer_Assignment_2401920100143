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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;//edge case: if the tree is empty
        swap(root->left, root->right);//swap values
        invertTree(root->left);//recursive left call
        invertTree(root->right);//recursive right call
    return root;    
    }
};
/*
Approach:
- Use recursion to traverse the tree.
- If the current node is NULL -> return NULL.
- Swap the left and right child of the current node.
- Recursively invert the left subtree.
- Recursively invert the right subtree.
- Return the root of the inverted tree.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
- h = height of the tree.
- Worst case (skewed tree): O(n)
- Balanced tree: O(log n)
*/