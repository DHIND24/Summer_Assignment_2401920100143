#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea=0;
        vector<int>left(n), right(n);//store indices of nearest smaller elements
        stack<int> st;//stack to store the indices
        for(int i=0; i<n; i++){
            while(!st.empty() && (heights[st.top()] >= heights[i])) st.pop();
            if(st.empty()) left[i] = -1;//if  stack is empty -> store -1(default)
            else left[i] = st.top();//else store top of stack
            st.push(i);
        }
        while(!st.empty()) st.pop();//clear stack
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && (heights[st.top()] >= heights[i])) st.pop();
            if(st.empty()) right[i] = n;//if  stack is empty -> store size of stack
            else right[i] = st.top();//else store top of stack
            st.push(i);
        }
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, (right[i]-left[i]-1)*(heights[i]));//caclculate maximum area
        }
    return maxArea;    
    }
};
/*
Approach:
- Find the index of the nearest smaller element on the left for every bar.
- Find the index of the nearest smaller element on the right for every bar.
- For each bar:
  - Width = right[i] - left[i] - 1
  - Area = width * heights[i]
- Keep track of the maximum area among all bars.
Time Complexity: O(heights.size())
- Each index is pushed and popped from the stack at most once while finding nearest smaller elements.
Space Complexity: O(heights.size())
- Extra arrays for left and right boundaries and the stack.
*/