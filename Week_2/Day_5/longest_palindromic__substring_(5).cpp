#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int start = 0;// starting index of longest palindrome
    int maxlen = 1; // length of longest palindrome found
    // check odd length palindrome (single center at index i)
    void checkOdd(string &s, int i){
        int l = i, r = i;
        int n = s.length();
        //expand while characters match and pointers are valid
        while(l >= 0 && r < n && s[l] == s[r]){
            // if current palindrome is longer, update result
            if(r - l + 1 > maxlen){
                start = l;
                maxlen = r - l + 1;
            }
            //move pointers outward
            l--;
            r++;
        }
    }
    //check even length palindrome (center between i and i+1)
    void checkEven(string &s, int i){
        int l = i, r = i + 1;
        int n = s.length();
        // expand while characters match and pointers are valid
        while(l >= 0 && r < n && s[l] == s[r]) {
            // if current palindrome is longer, update result
            if(r - l + 1 > maxlen) {
                start = l;
                maxlen = r - l + 1;
            }
            // move pointers outward
            l--;
            r++;
        }
    }
    //main function
    string longestPalindrome(string s) {
        int n = s.length();
        // edge case: empty string
        if (n == 0) return "";
        // try every index as a center
        for (int i = 0; i < n; i++) {
            checkOdd(s, i);   // odd length check
            checkEven(s, i);  // even length check
        }
        // build the answer string manually (without substr)
        string ans = "";
        for(int i = start; i < start + maxlen; i++){
            ans += s[i];
        }
        return ans;
    }
};
/*
Approach:
- Treat each index as a possible center of a palindrome.
- Expand around the center to check odd-length palindromes.
- Expand around the gap between adjacent characters to check even-length palindromes.
- If a longer palindrome is found -> update its starting index and length.
- After checking all centers, return the longest palindrome found.
Time Complexity: O(n²)
- For each index, expansion may traverse the str
Space Complexity: O(1)
- Only a few variables are used for tracking indices and length.
*/