#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;//stores all non-zero elements
        for(int i=0; i < n; i++) {
            if(nums[i] != 0) temp.push_back(nums[i]);//collect non-zero elements
        }
        int nz = temp.size();//number of non-zero elements
        for(int i = 0; i < nz; i++) nums[i] = temp[i];//place non-zero elements at front
        for(int i = nz; i < n; i++) nums[i] = 0;//fill remaining positions with zeroes
    }
};
/*
Approach:
- Store all non-zero elements in a temporary array.
- Copy them back to the beginning of the original array.
- Fill the remaining positions with zeroes.
Time Complexity: O(n)
- Array is traversed a constant number of times.
Space Complexity: O(n)
- Extra space is used for the temporary array.
*/