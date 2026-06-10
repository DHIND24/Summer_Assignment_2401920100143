#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty() == 0) return true;//edge case : empty string will always be a subsequence
        //using 2-Pointer Approach
        for(int i=0, j=0; i<s.size() && j<t.size(); j++){
            if(s[i] == t[j]) i++;//if matching characters found -> update i pointer
            if(i == s.size()) return true;//if all characters of s matched -> return true
        }
    return false;    
    }
};
/*
Approach:
- Use two pointers for strings s and t.
- Traverse t while searching for characters of s in order.
- Move pointer i whenever a matching character is found.
- If all characters of s are matched, return true.
Time Complexity: O(t.size())
- Traverse string t at most once.
Space Complexity: O(1)
- Uses constant extra space.
*/