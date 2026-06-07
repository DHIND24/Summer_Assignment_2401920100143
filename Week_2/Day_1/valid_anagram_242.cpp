#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;//check if size of both strings are same
        int freq[26]={0};//to store frequency of each character
        for(char c : s){//for each character of source string -> update the frequency
            freq[c-'a']++;
        }
        for(char c : t){//for each character of target string -> decrease the frequency
            freq[c-'a']--;
        }
        for(int count : freq){
            if(count != 0) return false;//iterate through each frequency
        }
    return true;    
    }
};
/*
Approach:
- If the strings have different lengths, they cannot be anagrams.
- Count the frequency of each character in the first string.
- Decrease the frequency using the second string.
- If all frequencies become zero, the strings are anagrams.
Time Complexity: O(n)
- Single traversal of both strings.
Space Complexity: O(1)
- Frequency array size is fixed at 26.
*/