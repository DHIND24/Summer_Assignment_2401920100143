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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root==NULL) return ans;//if tree is empty
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;//direction flag 
        while(!q.empty()){
            int size=q.size();            
            vector<int> level(size);//store current level
            for(int i=0;i<size;i++){               
                TreeNode* temp=q.front();//get front node
                q.pop();               
                int idx=flag ? i : size-i-1;//normal or reverse indexing
                level[idx]=temp->val;               
                if(temp->left) q.push(temp->left);//push left child              
                if(temp->right) q.push(temp->right);//push right child
            }
            flag=!flag;//change direction
            ans.push_back(level);//store level answer
        }
    return ans;
    }
};
/*
Approach:
- Use a queue to perform level order traversal.
- Process one level at a time.
- For each level, create a vector of the required size.
- If traversing left-to-right, place values at index i.
- If traversing right-to-left, place values at index (size - i - 1).
- Push child nodes into the queue for the next level.
- After processing a level, toggle the traversal direction.
- Store the level in the answer.
Time Complexity: O(n)
- Every node is visited exactly once.
Space Complexity: O(n)
- Queue and answer vector may store up to n nodes.
*/