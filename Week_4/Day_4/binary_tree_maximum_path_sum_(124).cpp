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
    int helper(TreeNode* root,int &maxSum){
        if(root==NULL) return 0;//empty subtree contributes nothing
        int left=max(0,helper(root->left,maxSum));//ignore negative contribution from left subtree
        int right=max(0,helper(root->right,maxSum));//ignore negative contribution from right subtree
        maxSum=max(maxSum,left+right+root->val);//update maximum path sum
        return root->val+max(left,right);//return best one-side path
    }

    int maxPathSum(TreeNode* root){
        int maxSum=INT_MIN;
        helper(root,maxSum);
    return maxSum;
    }
};
/*
Approach:
- Use post-order traversal to calculate the maximum path sum.
- Recursively compute the maximum contribution from the left and right subtrees.
- Ignore negative contributions by treating them as 0.
- Update the maximum path sum using the current node and both subtree contributions.
- Return the current node value plus the larger subtree contribution to the parent.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- h = height of the tree
- Balanced tree: O(log n)
- Skewed tree: O(n)
*/