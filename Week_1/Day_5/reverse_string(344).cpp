#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());   --> This simplest code but uses STL Library
        //2-Pointer Approach :
        int l=0, r=s.size()-1; 
        while(l<r){
            swap(s[l], s[r]);//using STL function
            //Manual Swapping
            //int temp = s[l];
            //s[l] = s[r];
            //s[r] = temp;
            l++, r--;
        }
    }
};
/*
Approach:
- Use two pointers, one at the beginning and one at the end of the character array.
- Swap the characters at both pointers.
- Move both pointers inward after each swap.
- Continue until the pointers meet or cross each other.
Alternative Approach:
- Use reverse(s.begin(), s.end()) from the STL library.
- Simpler to write, but the two-pointer approach demonstrates the underlying logic.
Time Complexity: O(n)
- Each character is visited at most once.
Space Complexity: O(1)
- Reversal is performed in-place using constant extra space.
*/