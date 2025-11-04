/*
Postfix Evaluation
You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
Examples:

Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
*/

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int n = tokens.size();
    
    for (int i = 0; i < n; i++) {
        string s = tokens[i];
        
        // If token is operator
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int num2 = st.top(); st.pop();
            int num1 = st.top(); st.pop();
            
            int ans;
            if (s == "+") ans = num1 + num2;
            else if (s == "-") ans = num1 - num2;
            else if (s == "*") ans = num1 * num2;
            else if (s == "/") ans = num1 / num2;   // integer division
            
            st.push(ans);
        } 
        else {
            // convert string → int
            st.push(stoi(s));
        }
    }
    
    return st.top();  // final result
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Postfix Evaluation Result: " << evalRPN(tokens) << endl;
    return 0;
}
