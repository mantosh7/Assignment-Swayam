#include <bits/stdc++.h>
using namespace std;

// Check if substring s[i..j] is palindrome using memoization
int solve(int i, int j, string &s, vector<vector<int>> &dp) {
    if (i >= j) 
        return dp[i][j] = 1;   // single char or empty string is palindrome
    
    if (dp[i][j] != -1) 
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = solve(i + 1, j - 1, s, dp);

    return dp[i][j] = 0;
}

int countSubstrings(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (solve(i, j, s, dp))
                count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}

/*
Time Complexity:  O(n^2)
Space Complexity: O(n^2)
*/
