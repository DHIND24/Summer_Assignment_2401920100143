#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Using Two-Pointer Approach:
    int compress(vector<char>& chars) {
        int write=0, read=0;//position to write compressed characters and position to traverse the array
        while(read < chars.size()){
            char currChar = chars[read];//current character being processed
            int count = 0;//frequency of current character
            while(read < chars.size() && chars[read] == currChar){//count consecutive occurrences of currChar
                read++;
                count++;
            }
            chars[write++] = currChar;//write the character
            if(count > 1){//write frequency if character appears more than once
                string countStr = to_string(count);
                for(char digit : countStr) chars[write++] = digit;//write each digit of frequency
            }
        }
    return write;//new length of compressed array
    }
};

/*
Approach:
- Traverse the array and count consecutive occurrences of each character.
- Write the current character at the write position.
- If the frequency is greater than 1 -> write its digits one by one.
- Continue until all character groups are processed.
- Return the length of the compressed array.
Time Complexity: O(chars.size())
- Each character is visited once while counting frequencies.
Space Complexity: O(1)
- Compression is performed in-place using constant extra space.
*/