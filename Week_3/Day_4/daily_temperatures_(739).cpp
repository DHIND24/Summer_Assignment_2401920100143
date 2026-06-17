#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);//initialize result array with 0 (if no warm days -> temperature remains 0)
        stack<int> st;//to store the indices of array
        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){//current temperature is warmer than temperatures corresponding to indices stored in the stack
            int idx = st.top();//store the index at top after processing it
            st.pop();//pop the stack to get remaining tempertures
            result[idx] = i-idx;//number of days waited for a warmer temperature
            }
            st.push(i);//push the current index
        }
    return result;    
    }
};
/*
Approach:
- Use a stack to store indices of temperatures whose answer is not yet known.
- Traverse the temperatures array from left to right.
- If the current temperature is warmer than the temperature at the index on top of the stack:
  - Pop the index from the stack.
  - Calculate the number of days waited using the difference of indices.
- Repeat until the stack becomes empty or a warmer temperature is no longer found.
- Push the current index into the stack.
- Any indices left in the stack do not have a warmer future temperature, so their answers remain 0.
Time Complexity: O(temperatures.size())
- Each index is pushed and popped from the stack at most once.
Space Complexity: O(temperatures.size())
- In the worst case, all indices may be stored in the stack.
*/
