#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;
    void recurse(string& curr, int openCnt, int closeCnt, int n) {
        if(curr.size()==2*n){//valid parenthesis combination formed
            result.push_back(curr);//store current combination
            return;//stop recursion for current combination
        }
        if(openCnt < n){//opening bracket can still be added
            curr.push_back('(');//add opening bracket
            recurse(curr, openCnt + 1, closeCnt, n);//explore further combinations
            curr.pop_back();//remove previously added bracket
        }
        if(closeCnt < openCnt){//add a closing bracket only if it keeps the string valid
            curr.push_back(')');//add closing bracket
            recurse(curr, openCnt, closeCnt + 1, n);//explore further combinations
            curr.pop_back();//remove previously added bracket
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;//to store current parentheses combination being built
        recurse(curr, 0, 0, n);//start generating from an empty string
    return result;
    }
};
/*
Approach:
- Use backtracking/recursion to build the current parenthesis string.
- If curr.size() == 2*n -> store the current combination in result.
- If openCnt < n -> add '(' and recurse.
- If closeCnt < openCnt -> add ')' and recurse.
- After each recursive call -> backtrack and explore other possibilities.
Time Complexity: O(4^n / sqrt(n))
- Backtracking explores all valid parenthesis combinations.
- The number of valid combinations increases rapidly as n grows.
- Each valid combination is generated exactly once.
Space Complexity: O(n)
- The recursion stack can grow up to n-levels deep.
*/