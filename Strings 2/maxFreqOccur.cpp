/*
Maximum occurring character in a string

Problem Statement: Given a string, return the character that occurs the maximum number of times in the string. If the maximum occurrence of two or more characters is the same, return any one of them.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char getMaxOccurringChar(string s) {
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int maxFreq = 0;
        char maxChar = '\0';

        for (auto it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

        return maxChar;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    char ans = obj.getMaxOccurringChar(s);

    cout << "Max occurring character: " << ans << endl;

    return 0;
}
