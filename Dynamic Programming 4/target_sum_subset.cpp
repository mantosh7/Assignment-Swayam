#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // (total - target) must be even and non-negative.
        // Otherwise no valid + / - assignment exists.
        if (total < target || (total - target) % 2 != 0)
            return 0;

        int s2 = (total - target) / 2;  // subset sum target

        return countSubsets(nums, s2);
    }

private:
    // Standard DP to count subsets that sum to given target
    int countSubsets(vector<int>& nums, int target) {
        int n = nums.size();

        // dp[i][j] = number of ways using first i numbers to make sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base Case: sum = 0 -> 1 way (choose empty subset)
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    // include or exclude
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    // cannot include
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Number of ways to reach target = "
         << sol.findTargetSumWays(nums, target) << endl;
    // Expected Output: 5

    return 0;
}

/*
Time Complexity:
    O(n * target_sum)
    where target_sum = (total - target) / 2

Space Complexity:
    O(n * target_sum)   – DP table
*/
