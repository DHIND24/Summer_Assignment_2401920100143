#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;//stores maximum area found so far
        for(int left=0, right=height.size()-1; left<right; ){
            int length = min(height[left], height[right]);//container height
            int width = right - left;//distance between two lines
            area = max(area, length*width);//update maximum area
            if(height[left] > height[right]) right--;//move shorter side
            else left++;
        }
    return area;    
    }
};
/*
Approach:
- Start with two pointers at the ends of the array.
- Calculate the area formed by the two lines.
- Move the pointer pointing to the shorter line.
- Continue until the pointers meet.
- Track the maximum area found.
Time Complexity: O(n)
- Each pointer moves at most n times.
Space Complexity: O(1)
- Uses only constant extra space.
*/