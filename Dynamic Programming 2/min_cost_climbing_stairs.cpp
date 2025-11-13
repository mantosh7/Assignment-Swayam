#include <bits/stdc++.h>
using namespace std;

// Memoized recursion to compute minimum cost from step i
int solve(int i, vector<int> &cost, vector<int> &dp) {

    // If crossed the last step, no more cost
    if (i >= cost.size())
        return 0;

    // If already computed, reuse it
    if (dp[i] != -1)
        return dp[i];

    // Option 1: Move 1 step ahead
    int oneStep = cost[i] + solve(i + 1, cost, dp);

    // Option 2: Move 2 steps ahead
    int twoStep = cost[i] + solve(i + 2, cost, dp);

    return dp[i] = min(oneStep, twoStep);
}

int main() {

    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    vector<int> dp(n, -1);

    // You can start from step 0 or 1, take the minimum
    int ans = min(solve(0, cost, dp), solve(1, cost, dp));

    cout << ans;

    return 0;
}
