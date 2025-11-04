/*
Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> bracket_map = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        // If ch is a closing bracket
        if (bracket_map.count(ch)) {
            if (st.empty() || st.top() != bracket_map[ch]) {
                return false;
            }
            st.pop();
        } 
        else {
            st.push(ch);
        }
    }

    return st.empty();
}

int main() {
    string s;
    cout << "Enter bracket string: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid parentheses" ;
    else
        cout << "Invalid parentheses" ;

    return 0;
}
