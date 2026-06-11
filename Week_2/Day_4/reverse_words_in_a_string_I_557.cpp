#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //Iterative Approach: Two-Pointer Method
        int beg=0;//stores starting index of current word
        for(int j=0; j<=s.size(); j++){
            if(s[j]==' ' || j==s.size()){//word boundary found  i.e. space or end of string
                int l=beg, r=j-1;//pointers for reversing current word
                while(l<r){ //reverse characters of current word
                    swap(s[l], s[r]);
                    l++, r--;
                }
                beg = j+1;//move to start of next word
            }
        }
    return s;   
    }
};
/*
Approach:
- Traverse the string character by character.
- Use spaces to identify the beginning and end of each word.
- Whenever a complete word is found, reverse it using two pointers.
- Keep the positions of spaces unchanged.
- Repeat until all words are processed.
Time Complexity: O(s.size())
- Each character is visited at most once.
Space Complexity: O(1)
- Reversal is performed directly in the original string.
*/

    //Recursive Approach:
/*
class Solution {
public:
    string solve(string s){
        int pos = s.find(' ');//find position of first space
        if(pos == string::npos){//base case: only last word
            reverse(s.begin(), s.end());
            return s;
        }
        string currword = s.substr(0, pos);//extract current word
        reverse(currword.begin(), currword.end());//reverse current word
        return currword + " " + solve(s.substr(pos + 1));//process remaining string
    }
    string reverseWords(string s) {
        return solve(s);
    }
};
Approach:
- Find the first word in the string.
- Reverse the current word.
- Recursively process the remaining part of the string.
- Combine the reversed current word with the recursive result.
- Stop when only one word remains.
Time Complexity: O(s.size()²)
- Multiple substr() operations create new strings during recursion.
Space Complexity: O(s.size())
- Extra space is used by recursive calls and temporary strings.
*/
