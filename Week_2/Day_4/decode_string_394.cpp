#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Using Recursion :
    string decode(string &s, int &idx){//Recursive Function
        string result;//stores decoded substring of current recursive call
        int repeatCount = 0;//stores number of repetitions
        while(idx < s.size()){
            if(s[idx] >= '0' && s[idx] <= '9'){//digit found -> build repeat count
                repeatCount = repeatCount * 10 + (s[idx] - '0');//build complete number
            }
            else if(s[idx] == '['){
                idx++;//move inside current bracket
                string decodedPart = decode(s, idx);//decode nested substring
                while(repeatCount--) result += decodedPart;//repeat decoded substring repeatCount times
                repeatCount = 0;//reset count for next pattern
            }
            else if(s[idx] == ']') return result;//current encoded block completely processed
            else result += s[idx];//add normal character to result
            idx++;
        }
        return result;//decoded substring for current recursive call
    }
    string decodeString(string s) {//Driver Function
        int idx = 0;//tracks current position while decoding
    return decode(s, idx);//decode complete string recursively
    }
};
/*
Approach:
- Traverse the string recursively.
- Build the repeat count whenever digits are encountered.
- When '[' is found, recursively decode the substring inside it.
- Repeat the decoded substring according to the repeat count.
- When ']' is reached, return the decoded substring to the previous recursive call.
- Continue until the complete string is decoded.

Time Complexity: O(decoded string length)
- Every character of the final decoded string is generated once.
Space Complexity: O(decoded string length)
- Extra space is used by recursion and the decoded result.
*/