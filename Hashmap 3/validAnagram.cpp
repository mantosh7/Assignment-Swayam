/*
Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int n = s.length();
    int m = t.length();

    if (n == 0 || m == 0 || n != m) return false;

    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;

    for (int i = 0; i < m; i++) {
        if (mp.find(t[i]) != mp.end() && mp[t[i]] != 0) {
            mp[t[i]]--;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << (isAnagram(s, t) ? "true" : "false");
    return 0;
}
