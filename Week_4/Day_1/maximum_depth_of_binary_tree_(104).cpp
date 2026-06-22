#include<bits/stdc++.h>
using namespace std;
/*
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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;//Base case: If the tree is empty, depth is 0
        //Recursively find the depth of left and right subtrees, take the maximum of the two, and add 1 for the current node.
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
/*
Approach:
- Use recursion to calculate the depth of the tree.
- If the current node is NULL -> return 0.
- Recursively find the depth of the left subtree.
- Recursively find the depth of the right subtree.
- The depth of the current node is 1 + maximum of left and right depths.
- Return the depth of the root node.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack stores at most h calls at a time.
- h = height of the tree.
- Worst case (skewed tree): O(n)
- Balanced tree: O(log n)
*/
