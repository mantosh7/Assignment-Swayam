#include <bits/stdc++.h>
using namespace std;

// Function to compute LCS length using bottom-up DP
int longestCommonSubsequence(string text1, string text2) {

    int n = text1.size();
    int m = text2.size();

    // dp[i][j] = length of LCS of text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // Characters match → include in LCS
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // Else take max of excluding one character
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// Driver code
int main() {
    string s1 = "abcde";
    string s2 = "ace";

    cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}

/*
Time Complexity:  O(n * m)
Space Complexity: O(n * m)
Where n = length of text1, m = length of text2
*/
