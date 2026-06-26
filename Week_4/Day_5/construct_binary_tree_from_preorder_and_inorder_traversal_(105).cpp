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
    unordered_map<int,int> mp;

    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart>preEnd || inStart>inEnd) return NULL;//no nodes left
        TreeNode* root=new TreeNode(preorder[preStart]);//first preorder element is root
        int idx=mp[root->val];//index of root in inorder
        int leftSize=idx-inStart;//number of nodes in left subtree
        root->left=helper(preorder,inorder, preStart+1, preStart+leftSize, inStart,idx-1);//build left subtree
        root->right=helper(preorder,inorder, preStart+leftSize+1, preEnd, idx+1,inEnd);//build right subtree
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;//store inorder indices
        return helper(preorder,inorder, 0,preorder.size()-1, 0,inorder.size()-1);
    }
};
/*
Approach:
- The first element of preorder is always the root.
- Find the root index in inorder using a hash map.
- Elements on the left of the root in inorder form the left subtree.
- Elements on the right form the right subtree.
- Recursively construct the left and right subtrees.
Time Complexity: O(n)
- Every node is processed exactly once.
Space Complexity: O(n)
- Hash map stores inorder indices.
- Recursion stack takes O(h).
*/