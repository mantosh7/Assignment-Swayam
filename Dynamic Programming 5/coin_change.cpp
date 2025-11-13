#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Memoized recursion for minimum coins
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        // Base case for first coin
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;  // impossible case
        }

        // Return stored value
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        // Do NOT take this coin
        int notTake = solve(idx - 1, amount, coins, dp);

        // Take this coin (stay on same index)
        int take = 1e9;
        if (coins[idx] <= amount)
            take = 1 + solve(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};


// Driver code
int main() {
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << sol.coinChange(coins, amount) << endl; // Output: 3

    return 0;
}
