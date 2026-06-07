#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int firstUniqChar(string s){
        int freq[26] = {0};
        //Count frequencies
        for(char c : s){
            freq[c - 'a']++;
        }
        //Find first unique character
        for(int i=0; i<s.length(); i++){
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

/*
Approach:
- Count the frequency of each character in the string.
- Traverse the string again.
- Return the index of the first character whose frequency is 1.
- If no such character exists, return -1.
Time Complexity: O(n)
- One pass for counting frequencies and one pass for finding the answer.
Space Complexity: O(1)
- Frequency array size is fixed at 26.
*/