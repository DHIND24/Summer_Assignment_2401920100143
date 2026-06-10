#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;//edge case : if needle size > haystack size -> needle is not part of haystack
        for(int i=0; i<=haystack.size()-needle.size(); i++){//check each possible substring of length needle.size()
            int j=0;//pointer for traversing needle needle
            while(j<needle.size() && haystack[i+j] == needle[j]) j++;//compare characters until mismatch or complete match
            if(j == needle.size()) return i;//if complete match occurs  -> return the index
        }
    return -1;    
    }
};
/*
Approach:
- Check every possible starting position in haystack.
- Compare characters of needle with the current substring.
- If all characters match, return the starting index.
- If no match is found, return -1.gcc --
Time Complexity: O((haystack.size()-needle.size()+1) * needle.size())
- Up to needle.size() characters may be compared for each starting position.
Space Complexity: O(1)
- Uses constant extra space.
*/