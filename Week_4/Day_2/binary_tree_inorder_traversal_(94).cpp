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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;//to store the inorder traversal
        traverse(root, result);//call the traversing function
    return result;
    }
private: 
    void traverse(TreeNode* root, vector<int>& res){
        if(root == NULL) return;//base case : 
        traverse(root->left, res);//left
        res.push_back(root->val);//root
        traverse(root->right, res);//right
    }
};
/*
Approach:
- Use recursion to perform inorder traversal.
- Traverse the left subtree first.
- Visit the current node and store its value.
- Traverse the right subtree.
- Continue until all nodes are processed.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(h)
- Recursion stack stores at most h function calls.
- h = height of the tree.
- Worst case (skewed tree): O(n)
- Balanced tree: O(log n)
*/