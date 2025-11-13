#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int take = 0;
            if (wt[i - 1] <= w)
                take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
            int notTake = dp[i - 1][w];
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << knapsack(val, wt, W);
    return 0;
}
