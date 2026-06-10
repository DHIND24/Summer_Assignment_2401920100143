#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*Divisor Based Checking : Check for each string
        //try every possible substring length
        for(int len = 1; len <= s.size()/2; len++){
            if(s.size() % len != 0) continue;//substring length must divide string size exactly
            bool flag = true;//assume current substring length forms the string
            for(int i = len; i < s.size(); i++){//compare each character with its corresponding character in the pattern
                if(s[i] != s[i%len]){
                    flag = false;//mismatch found
                    break;
                }
            }
            if(flag == true) return true;//repeating substring pattern found
        }
    return false;//no repeating substring pattern exists

Approach:
- Try every possible substring length from 1 to s.size()/2.
- A valid substring length must divide the string size exactly.
- Treat the first len characters as the repeating pattern.
- Compare each character with its corresponding character in the pattern using i % len.
- If all characters match for any valid len, return true.
- If no valid pattern is found, return false.
Time Complexity: O(s.size()²)
- Multiple substring lengths may need to be checked.
Space Complexity: O(1)
- Uses constant extra space.
*/

        //Doubled String trick : 
        string doubleS = s+s;//concatenate string with itself
        doubleS = doubleS.substr(1, doubleS.size()-2);//remove first and last character
    return doubleS.find(s) != string::npos;//check if original string exists in modified string
    }
};
/*
Approach:
- Concatenate the string with itself.
- Remove the first and last characters from the resulting string.
- If the original string is found in the modified string, it is formed by repeating a substring.
- Otherwise, no repeating substring pattern exists.
Time Complexity: O(s.size())
- String search is linear on average.
Space Complexity: O(s.size())
- Extra space is used for the concatenated string.
*/