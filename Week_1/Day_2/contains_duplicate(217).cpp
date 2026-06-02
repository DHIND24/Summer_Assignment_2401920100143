#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());//sort to bring equal elements together 
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]) return true;//duplicate found
        }
        return false;
    }
};
/*
Approach:
- Sort the array.
- Check adjacent elements for equality.
- If any two consecutive elements are equal, a duplicate exists.
Time Complexity: O(n log n)
- Sorting dominates the runtime.
Space Complexity: O(1)
- No extra data structures used(excluding sorting space).
*/