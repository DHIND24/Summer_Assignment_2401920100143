#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<long long>st;
    long long minel;
    MinStack(){
        minel = LLONG_MAX;
    }   
    void push(int val){
        if(st.empty()){
            st.push(0);//first element: store 0 as dummy value
            minel = val;//minel becomes this first element
        }
        else{
            long long diff = (long long)val - minel;//calculate difference between new value and current minimum
            st.push(diff);
            if(diff<0) minel = val;//update minel to this new smaller value
        }
    }   
    void pop(){
        //If diff < 0, we're popping the element that was the minimum -> need to restore the previous minimum
        // Previous min = current min - diff
        // Because diff = val - old_min, and val = current min
        // So old_min = current min - diff
       long long diff = st.top();
       st.pop();
       if(diff<0) minel -= diff;//if diff is negative, so subtracting negative = adding
    }
    int top(){
        long long diff = st.top();
        return (diff<0) ? minel : minel+diff;//if diff < 0, current top is the minimum element else reconstruct original value
    }
    int getMin(){
    return minel;//minel always stores current minimum
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
Approach:
- Maintain a stack of differences between the pushed value and the current minimum.
- Store the current minimum element separately in minel.
- While pushing:
  - If the stack is empty -> store 0 and set minel to the value.
  - Otherwise, store (value - minel).
  - If the difference is negative -> update minel because a new minimum is found.
- While popping:
  - If the stored difference is negative -> the popped element was the minimum.
  - Restore the previous minimum using the stored difference.
- For top():
  - If the difference is negative -> the top element is the current minimum.
  - Otherwise reconstruct the original value using minel + diff.
- getMin() simply returns minel.
Time Complexity: O(1)
- push(), pop(), top(), and getMin() all take constant time.
Space Complexity: O(n)
- One value is stored for each pushed element.
*/