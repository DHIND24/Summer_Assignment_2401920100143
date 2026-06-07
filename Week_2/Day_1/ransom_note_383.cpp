#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        for(char c:magazine) freq[c-'a']++;//count characters in magazine
        for(char c:ransomNote){//use characters for ransomNote
            if(freq[c-'a'] == 0) return false;//if character not available
            freq[c-'a']--;//use one occurrence of character
        }
    return true;        
    }
};
/*
Approach:
- Count the frequency of each character in magazine.
- Traverse ransomNote and use the required characters.
- If any required character is unavailable, return false.
- If all characters are successfully used, return true.
Time Complexity: O(m + n)
- One traversal of magazine and one traversal of ransomNote.
Space Complexity: O(1)
- Frequency array size is fixed at 26.
*/