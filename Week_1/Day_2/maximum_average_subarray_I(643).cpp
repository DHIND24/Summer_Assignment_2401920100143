#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;
        for(int i=0; i<k; i++) windowSum += nums[i];//build current window sum
        int maxSum = windowSum;//stores maximum window sum found so far
        for(int i=k; i<nums.size(); i++) {
            windowSum += nums[i] - nums[i-k];//update the current window sum
            maxSum = max(maxSum, windowSum);//update maximum windpow sum
        }
    return (double)maxSum / k;
    }
};
/*
Approach:
- Compute the current window sum for the first k elements.
- Slide the window by removing the outgoing element and adding the incoming element.
- Track the maximum window sum found so far.
- Return the corresponding average.
Time Complexity: O(n)
- Single traversal of the array.
Space Complexity: O(1)
- Uses only constant extra space.
*/