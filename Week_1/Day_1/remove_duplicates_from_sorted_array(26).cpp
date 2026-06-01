#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;//points to last unique element
        for(int j = 1; j < nums.size(); j++){//scan remaining elements
            if (nums[i] != nums[j]){//found a new unique element
                nums[i + 1] = nums[j];//place it next to previous unique
                i++;//move unique pointer forward
            }
        }
        return i + 1;//number of unique elements
    }
};
/*
Time Complexity: O(n)
- Single traversal of the array.
Space Complexity: O(1)
- No extra space used.
*/