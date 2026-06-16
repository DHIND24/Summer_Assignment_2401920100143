#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        //Stack-based Approach :
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);//push opening bracket
            }
            else{
                if(st.empty()) return false;//no matching opening bracket
                char open = st.top();//get top opening bracket
                st.pop();//remove it from stack
                if((c == ')' && open != '(') ||
                   (c == '}' && open != '{') ||
                   (c == ']' && open != '[')) return false;//mismatched bracket pair
            }
        }
    return st.empty();//all brackets matched if stack is empty
    }
    //Raw Array Implementation: 
    /*
    bool isValid(string s) {
        char stack[10000];
        int top = -1;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack[++top] = c; 
            } else {
                if (top == -1) return false;
                char open = stack[top--];    
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '['))
                    return false;
            }
        }
        return top == -1;
    }
    */
};
/*
Approach:
- Use a stack to store opening brackets.
- If the current character is an opening bracket -> push it onto the stack.
- If the current character is a closing bracket:
  - Check if the stack is empty -> return false.
  - Pop the top opening bracket and verify that it matches.
- After processing all characters, the stack should be empty for the string to be valid.
Time Complexity: O(s.size())
- Each bracket is pushed and popped at most once.
Space Complexity: O(s.size())
- In the worst case, all characters may be opening brackets and stored in the stack.
*/