#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    bool isPalindrome(string s, int i = 0) {
        //Step 1: preprocess -> keep only lowercase alphanumeric
        string cleaned = "";
        for(char c : s) {
            if (isalnum(c)) {
                cleaned.push_back(tolower(c));
            }
        }
        //Step 2: call recursion on cleaned string
        return checkPalindrome(cleaned, i);
    }
private:
    bool checkPalindrome(const string& s, int i) {
        if(i >= s.size() / 2) return true;                      //base case
        if(s[i] != s[s.size() - i - 1]) return false;           //mismatch
        return checkPalindrome(s, i + 1);                        //recurse
    }
};
Alternative Recursive Approach:
- Create a cleaned string containing only lowercase alphanumeric characters.
- Recursively compare characters from both ends.
- If all corresponding characters match, the string is a palindrome.
Time Complexity: O(n)
- One pass to clean the string and one recursive pass to check palindrome.
Space Complexity: O(n)
- O(n) for the cleaned string.
- O(n) recursion stack.
*/

// 2-Pointer Approach :  O(1) extra space
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;//pointers at both ends
        while(left < right){
            if(!isalnum(s[left])){
                left++;//skip non-alphanumeric character from left
                continue;
            }
            if(!isalnum(s[right])){
                right--;//skip non-alphanumeric character from right
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;//mismatch found
            left++;//move left pointer inward
            right--;//move right pointer inward
        }
    return true;
    }
};
/*
Approach:
- Use two pointers starting from both ends of the string.
- Skip non-alphanumeric characters.
- Compare characters after converting them to lowercase.
- If any pair mismatches, return false.
- If all pairs match, return true.
Time Complexity: O(n)
- Each character is processed at most once.
Space Complexity: O(1)
- Uses only constant extra space.
*/