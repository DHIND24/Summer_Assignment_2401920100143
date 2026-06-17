#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;//stores operands and intermediate results
        for(const std::string& token : tokens){
            // Check if the token is an operator
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                //pop the two operands
                int b = st.top(); st.pop(); //right operand
                int a = st.top(); st.pop(); //left operand
                //perform the operation and push back
                if (token == "+") st.push(a + b);
                else if(token == "-") st.push(a-b);
                else if(token == "*") st.push(a*b);
                else if(token == "/") st.push(a/b); 
            }    
            else 
                st.push(std::stoi(token));//token is a number -> convert string to integer and push
        }
    return st.top();
    }
};
/*
Approach:
- Traverse each token in the expression.
- If the token is a number -> convert it to an integer and push it onto the stack.
- If the token is an operator:
  - Pop the top two operands from the stack.
  - Apply the operator in the correct order.
  - Push the result back onto the stack.
- After processing all tokens, the remaining element in the stack is the answer.
Time Complexity: O(tokens.size())
- Each token is processed exactly once.
Space Complexity: O(tokens.size())
- The stack may store all operands in the worst case.
*/