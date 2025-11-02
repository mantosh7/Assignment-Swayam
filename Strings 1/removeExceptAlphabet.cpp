/*
Remove all characters other than alphabets
Given a string S, remove all the characters other than the alphabets.

Example 1:

Input: S = "$Gee*k;s..fo, r'Ge^eks?"
Output: GeeksforGeeks
Explanation: Removed charcters other than
alphabets. 
*/

#include <bits/stdc++.h>
using namespace std;

string removeSpecialCharacter(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ans += s[i];
    }
    if (ans == "") return "-1";
    return ans;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = removeSpecialCharacter(s);
    cout << "Output: " << result << endl;

    return 0;
}
