#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int currSum=nums[0];//currSum stores maximum subarray sum ending at current index
        int maxSum=nums[0];//maxSum stores overall maximum subarray sum found so far
        //using Kadane's algorithm 
        for(int i=1; i<nums.size(); i++){
            currSum = max(currSum + nums[i], nums[i]);//either extend previous subarray or start new subarray from current element
            maxSum = max(maxSum, currSum);//update the maxSum if current subarray sum is better
        }
    return maxSum;
    }
};
/*
Approach:
- Use Kadane's Algorithm.
- At each index, either extend the current subarray or start a new one.
- Track the maximum subarray sum found so far.
Time Complexity: O(n)
- Single traversal of the array.
Space Complexity: O(1)
- Uses only constant extra space.
*/