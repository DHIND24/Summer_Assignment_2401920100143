#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";//if the input list is empty -> return empty string
        sort(strs.begin(), strs.end());//Sort the array of strings lexicographically
        /*Take first and last string after sorting these two will have the minimum common prefix among all*/
        string fst = strs[0], lst = strs[strs.size()-1];
        string result = "";
        for(int i=0; i<min(fst.size(), lst.size()); i++){//compare characters of first and last string
            if(fst[i] != lst[i]) break;//if first string is NOT equal to last string i.e. smallest is not largest string
            result += fst[i];
        }
    return result;    
    }
};
/*
Approach:
- Sort the strings lexicographically.
- Compare the first and last string after sorting.
- The common prefix between them is the longest common prefix of all strings.
- Build and return the common prefix character by character.
Time Complexity: O(n * m * log n)
- Sorting n strings of average length m dominates the runtime.
Space Complexity: O(1)
- Excluding the space used for the output string.
*/