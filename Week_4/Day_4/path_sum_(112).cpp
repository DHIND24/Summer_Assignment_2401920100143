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
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root == NULL) return false;//edge case: leaf node
        if(root->left == NULL && root->right == NULL) return targetSum == root->val;
        int remSum = targetSum - root->val;
    return hasPathSum(root->left, remSum)||hasPathSum(root->right, remSum);
    }
};
/*
Approach:
- Start from the root and subtract the current node value from targetSum.
- If a leaf node is reached, check whether the remaining sum equals the leaf value.
- Recursively check the left and right subtrees with the updated sum.
- If any root-to-leaf path matches the target sum, return true.
- Otherwise, return false.
Time Complexity: O(n)
- Every node is visited at most once.
Space Complexity: O(h)
- Recursion stack depth equals the height of the tree.
- Balanced tree: O(log n)
- Skewed tree: O(n)
*/