#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns maximum money that can be robbed without taking adjacent houses
    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // dp[i] = maximum money collectible up to index i
        vector<int> dp(n, 0);

        dp[0] = nums[0];                       // First house → must take it
        dp[1] = max(nums[0], nums[1]);         // Between first two, choose max

        // Build the DP values
        for (int i = 2; i < n; i++) {
            int skip = dp[i - 1];              // Skip current house
            int take = dp[i - 2] + nums[i];    // Take current → can't take previous
            dp[i] = max(skip, take);
        }

        return dp[n - 1];
    }
};

int main() {

    Solution s;

    vector<int> nums1 = {2, 7, 9, 3, 1};
    cout << "Maximum loot: " << s.rob(nums1) << endl;   // 12

    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Maximum loot: " << s.rob(nums2) << endl;   // 4

    return 0;
}

/*
Time Complexity:  O(n)
Space Complexity: O(n)
*/
