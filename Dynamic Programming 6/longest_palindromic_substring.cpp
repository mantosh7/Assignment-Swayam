#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();

    // dp[i][j] = true if substring s[i..j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0;       // starting index of longest palindrome
    int maxLength = 1;   // at least 1 character is always a palindrome

    // Step 1: Single characters are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Step 2: Check 2-length substrings
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Step 3: Check substrings of length >= 3
    for (int len = 3; len <= n; len++) {

        // i = starting index
        for (int i = 0; i <= n - len; i++) {

            int j = i + len - 1; // ending index

            // Conditions:
            // 1. s[i] == s[j]
            // 2. Inside substring s[i+1..j-1] must also be palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1]) {

                dp[i][j] = true;

                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    // return longest palindromic substring
    return s.substr(start, maxLength);
}

// Driver code
int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}

/*
Time Complexity:  O(n^2)
Space Complexity: O(n^2)
*/
