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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int& diameter) {
        if(root == NULL) return 0;//base Case: An empty node has a height of 0
        int leftHeight = height(root->left, diameter), rightHeight = height(root->right, diameter);//Post-order traversal
        diameter = max(diameter, leftHeight + rightHeight);//The longest path passing through the CURRENT node as the root of the path is the sum of the maximum depths of its left and right subtrees.
        return 1 + max(leftHeight, rightHeight);//Height = 1 + the height of the deeper subtree
    }
    int diameterOfBinaryTree(TreeNode* root){
        int diameter=0;
        height(root, diameter);
    return diameter;
    }
};
/*
Approach:
- Use post-order DFS to compute the height of each subtree.
- For every node, calculate the heights of its left and right subtrees.
- The longest path passing through the current node is leftHeight + rightHeight.
- Update the maximum diameter whenever a larger value is found.
- Return the height of the current subtree to the parent.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
- Balanced tree: O(log n)
- Skewed tree: O(n)
*/