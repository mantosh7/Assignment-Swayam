#include <bits/stdc++.h>
using namespace std;

int findCoins(vector<int>& nums, int amount, int idx, vector<vector<int>>& dp) {
    if (amount == 0) return 0;
    if (idx < 0) return INT_MAX - 1;
    if (dp[idx][amount] != -1) return dp[idx][amount];

    int take = INT_MAX - 1;
    if (nums[idx] <= amount)
        take = 1 + findCoins(nums, amount - nums[idx], idx, dp);

    int notTake = findCoins(nums, amount, idx - 1, dp);

    return dp[idx][amount] = min(take, notTake);
}

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int ans = findCoins(nums, amount, n - 1, dp);

    if (ans >= INT_MAX - 1)
        cout << -1;
    else
        cout << ans;

    return 0;
}
