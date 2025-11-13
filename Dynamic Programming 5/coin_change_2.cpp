#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoized recursive function
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        // Base case: only coin 0 left
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];   // use coin[0] repeatedly
            else
                return 1e9;                 // not possible
        }

        // If already computed
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        // Option 1: Do not take the coin
        int notTake = solve(idx - 1, amount, coins, dp);

        // Option 2: Take the coin (stay at same index)
        int take = 1e9;
        if (coins[idx] <= amount)
            take = 1 + solve(idx, amount - coins[idx], coins, dp);

        // Store minimum of both choices
        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};

int main() {
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << sol.coinChange(coins, amount) << endl;  // Output: 3

    return 0;
}

/*
Time Complexity:  O(n * amount)
Space Complexity: O(n * amount) + recursion stack
*/
