#include <bits/stdc++.h>
using namespace std;

// Compute minimum number of perfect squares that sum to n
int numSquares(int n) {

    // dp[i] = minimum squares needed to form i
    vector<int> dp(n + 1, INT_MAX);

    // Base case: 0 needs 0 squares
    dp[0] = 0;

    // Fill dp table from 1 to n
    for (int i = 1; i <= n; i++) {

        // Try all square numbers <= i
        for (int s = 1; s * s <= i; s++) {
            int sq = s * s;
            dp[i] = min(dp[i], 1 + dp[i - sq]);
        }
    }

    return dp[n];
}

int main() {

    int n;
    cin >> n;

    cout << numSquares(n);

    return 0;
}
