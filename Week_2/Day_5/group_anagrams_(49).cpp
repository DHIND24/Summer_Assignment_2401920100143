#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Using Hash-Map to group anagrams
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;//stores strings grouped by sorted representation
        for(string &str : strs){
            string sortedStr = str;//create a copy for sorting
            sort(sortedStr.begin(), sortedStr.end());//anagrams will have the same sorted string
            groups[sortedStr].push_back(str);//group current string with its anagrams
        }
        vector<vector<string>> result;
        for(auto& it : groups) result.push_back(it.second);//add current anagram group to result
    return result;
    }
};

/*
Approach:
- Sort each string to obtain its sorted representation -> anagrams will have same sorted representation
- Use the sorted string as a key in a hash map.
- Group all strings having the same sorted representation.
- Collect all groups from the hash map and return them.
Time Complexity: O(n*k*log k)
- n = number of strings.
- k = average length of a string.
- Each string is sorted once.
Space Complexity: O(n * k)
- Hash map stores all strings and their grouped representations.
*/