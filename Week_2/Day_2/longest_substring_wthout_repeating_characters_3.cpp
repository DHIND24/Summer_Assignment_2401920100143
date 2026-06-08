#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[128] = {0};//stores frequency of characters in current window
        int left = 0, maxLen = 0;
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;//include current character in window
            while(freq[s[right]] > 1){//duplicate character found
                freq[s[left]]--;//remove leftmost character
                left++;//shrink window
            }
            maxLen = max(maxLen, right - left + 1);//update longest window
        }
    return maxLen;
    }
};
/*
Approach:
- Use a sliding window to maintain a substring with unique characters.
- Expand the window by including characters from the right.
- If a duplicate character appears, shrink the window from the left.
- Track the maximum valid window length.
Time Complexity: O(n)
- Each character is added and removed from the window at most once.
Space Complexity: O(1)
- Frequency array size is fixed at 128.
*/