#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        int pos = nums.size() - 1;//start filling from last index
        while(left <= right){
            int leftSquare = nums[left] * nums[left];//square of left element
            int rightSquare = nums[right] * nums[right];//square of right element
            if(leftSquare > rightSquare) {
                result[pos] = leftSquare;//place larger square
                left++;//move left pointer inward
            }
            else{
                result[pos] = rightSquare;//place larger square
                right--;//move right pointer inward
            }
            pos--;//move to next position in result array
        }
    return result;
    }
};
/*
Approach:
- The largest square can come from either the leftmost or rightmost element.
- Compare the squares of both elements.
- Place the larger square at the end of the result array.
- Move the corresponding pointer and repeat.
- Continue until all positions are filled.
Time Complexity: O(n)
- Each element is processed once.
Space Complexity: O(n)
- Uses an extra array to store the result.
*/