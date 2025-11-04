/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
        // Constructor (can stay empty)
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else {
            int currentMin = st.top().second;
            st.push({val, min(val, currentMin)});
        }
    }
    
    void pop() {
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        if(!st.empty())
            return st.top().first;
        return -1; // optional safeguard
    }
    
    int getMin() {
        if(!st.empty())
            return st.top().second;
        return -1; // optional safeguard
    }
};

// 🧪 Local Testing (Not required for LeetCode)
int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << "Current Min: " << obj.getMin() << endl;  // Output: -3
    obj.pop();
    cout << "Top Element: " << obj.top() << endl;     // Output: 0
    cout << "Current Min: " << obj.getMin() << endl;  // Output: -2
    return 0;
}
