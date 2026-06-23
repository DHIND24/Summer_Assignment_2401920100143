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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;//to store the final result
        if(root == NULL) return result;//edge case: empty tree
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();//nodes in current level
            vector<int> level;//to store the nodes in each level 
            for(int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);//store current node value
                if (curr->left)  q.push(curr->left);//add left child to queue if it exists
                if (curr->right) q.push(curr->right);//add right child to queue if it exists
            }
            result.push_back(level);//store values of current level in result array 
        }
    return result;
    }
};
/*
Approach:
- Use a queue to perform level order traversal.
- Start by pushing the root node into the queue.
- Process one level at a time.
- For each level:
  - Determine the number of nodes currently in the queue.
  - Remove each node from the queue and store its value.
  - Push its left and right children into the queue if they exist.
- Store the current level in the result.
- Continue until the queue becomes empty.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(n)
- The queue may store all nodes of a level.
- The result vector also stores all node values.
*/