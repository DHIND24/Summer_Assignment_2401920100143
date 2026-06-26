#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
        //Using Level Order Traversal
        if(root==NULL) return "";//empty tree
        string result="";
        queue<TreeNode*> q;
        q.push(root);//start traversal from root
        while(!q.empty()){
            TreeNode* curr=q.front();//get current node
            q.pop();//remove it from queue
            if(curr==NULL){
                result+="N,";//store NULL marker
                continue;
            }
            result+=to_string(curr->val)+",";//store current node value
            q.push(curr->left);//push left child (even if NULL)
            q.push(curr->right);//push right child (even if NULL)
        }
        return result;
    }
/*
Approach (Serialization):
- Perform level order traversal using a queue.
- Store every node value in the result string.
- Whenever a NULL node is encountered, store "N".
- Push both left and right children of every non-null node into the queue.
- Continue until the queue becomes empty.
*/    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data=="") return NULL;//empty tree
        stringstream ss(data);//read serialized string
        string str;
        getline(ss,str,',');//read root value
        TreeNode* root=new TreeNode(stoi(str));//create root node
        queue<TreeNode*> q;
        q.push(root);//start reconstruction from root
        while(!q.empty()){
            TreeNode* curr=q.front();//current parent node
            q.pop();
            //Build left child
            getline(ss,str,',');//read next value
            if(str!="N"){
                curr->left=new TreeNode(stoi(str));//create left child
                q.push(curr->left);//process it later
            }
            //Build right child
            getline(ss,str,',');//read next value
            if(str!="N"){
                curr->right=new TreeNode(stoi(str));//create right child
                q.push(curr->right);//process it later
            }
        }
        return root;
    }
/*
Approach (Deserialization):
- Read the first value and create the root node.
- Use a queue to rebuild the tree level by level.
- For every node removed from the queue:
  - Read the next value and create its left child if it is not "N".
  - Read the following value and create its right child if it is not "N".
- Push every newly created child into the queue.
- Continue until all values are processed.
*/
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/*
Time Complexity: O(n)
- Every node is serialized exactly once.
- Every node is deserialized exactly once.
Space Complexity: O(n)
- Queue stores nodes during level order traversal.
- Serialized string also stores all node values and NULL markers.
*/
