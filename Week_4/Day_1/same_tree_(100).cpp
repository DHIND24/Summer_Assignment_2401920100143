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
    void traverse(TreeNode* root, vector<int>& res){
        if(root == NULL){//base case
            res.push_back(INT_MIN);// NULL marker
            return;
        }
        res.push_back(root->val);//root
        traverse(root->left, res);//left
        traverse(root->right, res);//right    
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> t1, t2;
        traverse(p, t1);
        traverse(q, t2);
    return t1 == t2;
    }
};
/*
Approach:
- Perform a preorder traversal on both trees.
- Store node values in separate vectors.
- For NULL nodes, store a special marker to preserve tree structure.
- Compare the two traversal vectors.
- If both vectors are identical, the trees are the same.
Time Complexity: O(n)
- Every node of both trees is visited once.
Space Complexity: O(n)
- Traversal vectors store all nodes and NULL markers.
*/