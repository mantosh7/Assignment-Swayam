#include <bits/stdc++.h>
using namespace std;

// Recursive LCS function with memoization
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

    // If any index goes out of range, no palindrome possible
    if (i < 0 || j < 0)
        return 0;

    // Return cached value
    if (dp[i][j] != -1)
        return dp[i][j];

    // If characters match, take them in subsequence
    if (s[i] == t[j])
        return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);

    // Otherwise, check both possibilities
    return dp[i][j] = max(
        solve(i - 1, j, s, t, dp),
        solve(i, j - 1, s, t, dp)
    );
}

int LongestPalindromicSubsequence(string s) {

    // Reverse string to compare with original (LPS = LCS(s, reverse(s)))
    string t = s;
    reverse(t.begin(), t.end());

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(n - 1, n - 1, s, t, dp);
}

int main() {
    string s;
    cin >> s;

    cout << LongestPalindromicSubsequence(s);
    return 0;
}

/*
Time Complexity:  O(n^2)
Space Complexity: O(n^2)   // due to DP table + recursion stack
*/
