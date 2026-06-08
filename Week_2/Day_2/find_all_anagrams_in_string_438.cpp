#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int len1 = p.size(), len2 = s.size();
        if(len1 > len2) return result;//anagram not possible
        vector<int> freqP(26, 0); 
        vector<int> freqS(26, 0);
        for(char ch : p) freqP[ch - 'a']++;//store frequency of each character os string 'p'
        int left = 0;
        for(int right = 0; right < len2; right++) {
            //Expand the window by adding the current character
            freqS[s[right] - 'a']++; 
            //If window size exceeds len1 -> shrink it from the left immediately
            if(right-left+1 > len1){
                freqS[s[left] - 'a']--; 
                left++;
            }
            //check for an anagram only when the window is exactly the right size
            if(right-left+1 == len1 && freqS == freqP) result.push_back(left);//if window size equals len1 and frequencies match -> store starting index
        }
        return result;
    }
};
/*
Approach:
- Store the frequency of characters in p.
- Use a sliding window of size len1 on s.
- Expand the window from the right and shrink it from the left when needed.
- If the current window frequency matches freqP, store the starting index.
Time Complexity: O(n)
- Each character is processed once.
- Comparing two frequency arrays takes O(26), which is constant.
Space Complexity: O(1)
- Frequency arrays have fixed size 26.
*/