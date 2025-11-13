#include <bits/stdc++.h>
using namespace std;

// Memoized recursion to count number of ways to reach step i
int countWays(int i, vector<int> &dp) {

    // Base cases: 0 or 1 step has exactly 1 way
    if (i <= 1)
        return 1;

    // If already computed, reuse it
    if (dp[i] != -1)
        return dp[i];

    // Recurrence: ways(n) = ways(n-1) + ways(n-2)
    dp[i] = countWays(i - 1, dp) + countWays(i - 2, dp);

    return dp[i];
}

int main() {
    
    int n;
    cin >> n;

    // DP array initialized with -1 (means "not solved yet")
    vector<int> dp(n + 1, -1);

    // Compute and print answer
    cout << countWays(n, dp);

    return 0;
}
