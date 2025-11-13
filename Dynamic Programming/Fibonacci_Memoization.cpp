#include <bits/stdc++.h>
using namespace std;

// Memoized Fibonacci function
int solveFib(int n, vector<int> &dp) {

    // Base values for Fibonacci
    if (n <= 1)
        return n;

    // If already calculated, return stored value
    if (dp[n] != -1)
        return dp[n];

    // Otherwise compute and store in dp
    dp[n] = solveFib(n - 1, dp) + solveFib(n - 2, dp);

    return dp[n];
}

int main() {

    // Take input
    int n;
    cin >> n;

    // DP array initialized with -1 (meaning "not computed yet")
    vector<int> dp(n + 1, -1);

    // Call memoized function
    int result = solveFib(n, dp);

    // Print result
    cout << result;

    return 0;
}
