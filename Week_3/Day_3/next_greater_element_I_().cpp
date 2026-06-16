#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;//to store the element and its next greater element      
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();//remove all elements smaller than or equal to current element          
            if(!st.empty()) mp[nums2[i]] = st.top();//if stack is not empty -> top element = next greater element 
            else mp[nums2[i]] = -1;//if stack is empty : then no next greater element exists    
            st.push(nums2[i]);//push current element into stack
        }
        for(int el : nums1) ans.push_back(mp[el]);//for each element of nums1: push its next greater element        
    return ans;    
    }
};
/*
Approach:
- Traverse nums2 from right to left.
- Maintain a decreasing stack to find the next greater element efficiently.
- Remove all elements from the stack that are smaller than or equal to the current element.
- If the stack is not empty -> its top is the next greater element.
- Otherwise, no next greater element exists and store -1.
- Store the mapping in a hash map.
- Traverse nums1 and use the hash map to get the answer for each element.
Time Complexity: O(nums1.size() + nums2.size())
- Each element of nums2 is pushed and popped at most once.
- Looking up answers for nums1 takes linear time.
Space Complexity: O(nums2.size())
- Stack and hash map may store all elements of nums2.
*/