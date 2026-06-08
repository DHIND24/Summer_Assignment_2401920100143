#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if(len1 > len2) return false;
        int freq[26] = {0}, left = 0, right = 0;//freq stores how many characters we need, left, right are pointer of window
        for(char ch : s1){//store frequency of characters in s1
            freq[ch - 'a']++;
        }
        while(right < len2){//traverse s2 using sliding window
            freq[s2[right] - 'a']--;//include current character in window
            while(freq[s2[right] - 'a'] < 0){//if frequency goes negative -> shrink window
                freq[s2[left] - 'a']++;
                left++;
            }
            if(right-left+1 == len1) return true;//check window size 
            right++;
        }
    return false;
    }
};
/*
Approach:
- Store the frequency of characters in s1.
- Use a sliding window on s2.
- Expand the window by including characters from the right.
- If a character count becomes negative, shrink the window from the left.
- If a valid window of size len1 is found, return true.
Time Complexity: O(n)
- Each character is visited at most twice by the sliding window.
Space Complexity: O(1)
- Frequency array size is fixed at 26.
*/