#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>st1, st2;
    MyQueue() {
        
    }
    void push(int x){
        st1.push(x);
    }
    int pop(){
        if(st2.empty()){//only tranfer if second stack is empty
            while(!st1.empty()){
            st2.push(st1.top());//push the top element of original stack into second stack
            st1.pop();//remove the top element 
            }
        }
        int el = st2.top();//store the element at top
        st2.pop();
    return el;  
    }
    int peek(){
        if(st2.empty()){
            while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            }
        }
    return st2.top();//return the top element 
    }
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
Approach:
- Use two stacks:
  - st1 for incoming elements.
  - st2 for outgoing elements.
- For push():
  - Insert the element into st1.
- For pop() and peek():
  - If st2 is empty, transfer all elements from st1 to st2.
  - This reverses the order and makes the oldest element available on top.
- For empty():
  - The queue is empty only if both stacks are empty.
  
Time Complexity:
- push(): O(1)
- pop(): O(1) amortized
- peek(): O(1) amortized
- empty(): O(1)
Explanation:
- Each element is moved from st1 to st2 at most once.
Space Complexity: O(n)
- Both stacks together store all queue elements.
*/