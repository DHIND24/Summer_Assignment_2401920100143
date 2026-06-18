#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //BRUTE FORCE IDEA :
        /*
        vector<int> result;
        for(int i=0; i <= nums.size()-k; i++){
            int mx = nums[i];
            for(int j=i; j<i+k; j++){
                mx = max(mx, nums[j]);
            }
            result.push_back(mx);
        }
    return result;

        Approach:
        - Consider every window of size k.
        - Find the maximum element in the current window by scanning all k elements.
        - Store the maximum in the result array.
        - Slide the window by one position and repeat.

        Time Complexity: O((n-k+1)*k)
        Space Complexity: O(1)
        */

        // OPTIMIZED SOLUTION 
        vector<int> result;
        deque<int> dq;//stores indices of useful elements
        for(int i=0; i<nums.size(); i++){
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();//remove indices that are outside the current window
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();//remove smaller elements as they can never become maximum
            dq.push_back(i);//add current index
            //window condition: first window is formed when i reaches k-1
            if(i >= k-1) result.push_back(nums[dq.front()]);//front stores maximum of current window
        }
    return result;
    }
};
/*
Optimal Approach (Monotonic Deque):
- Use a deque to store indices of useful elements.
- Remove indices from the front if they are outside the current window.
- Remove indices from the back while their values are smaller than or equal to the current element.
- Push the current index into the deque.
- Once the first window is formed, the front of the deque stores the maximum element.
- Store the maximum for every window.
Time Complexity: O(nums.size())
- Each index is pushed and popped at most once.
Space Complexity: O(k)
- The deque stores at most k indices.
*/