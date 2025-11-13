#include <bits/stdc++.h>
using namespace std;

// Bottom-up DP approach to compute Fibonacci
int fibTab(int n) {

    // Direct answer for n = 0
    if (n == 0)
        return 0;

    // DP array to store results from 0 to n
    vector<int> dp(n + 1);

    // Base values
    dp[0] = 0;
    dp[1] = 1;

    // Fill table from index 2 up to n
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Use previously computed values
    }

    // Final Fibonacci result
    return dp[n];
}

int main() {

    int n;
    cin >> n;

    cout << fibTab(n);

    return 0;
}
