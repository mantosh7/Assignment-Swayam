/*
Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

Example:
Input: s = "testsample"
Output: 'e'
Explanation: 'e' is the character which is having the highest frequency.
*/

#include <bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string &s) {
    unordered_map<char, int> mp;

    for (char ch : s)
        mp[ch]++;

    int maxi = 0;
    char maxChar = 'z';

    for (auto it : mp) {
        if (it.second > maxi) {
            maxi = it.second;
            maxChar = it.first;
        }
        else if (it.second == maxi) {
            if (it.first < maxChar)
                maxChar = it.first;
        }
    }
    return maxChar;
}

int main() {
    string s = "testsample";
    cout << getMaxOccuringChar(s) << endl;
    return 0;
}
