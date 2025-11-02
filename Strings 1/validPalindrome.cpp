/*
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string result;
    for (auto c : s) {
        c = tolower(c);
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) && (c != ' ')) {
            result += c;
        }
    }

    int i = 0, j = result.size() - 1;
    while (i < j) {
        if (result[i] != result[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
