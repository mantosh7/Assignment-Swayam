#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if we can jump to the end
bool canReach(int idx, vector<int>& nums, vector<int>& dp) {
    int n = nums.size() - 1;

    // If we reached the last index
    if (idx == n) return true;

    // Memo: -1 = not visited, 0 = false, 1 = true
    if (dp[idx] != -1) return dp[idx];

    int maxJump = nums[idx];  // Maximum steps we can jump from here

    // Try all jump lengths from 1 to maxJump
    for (int step = 1; step <= maxJump; step++) {
        if (idx + step <= n && canReach(idx + step, nums, dp)) {
            return dp[idx] = 1;  // We found a valid path
        }
    }

    return dp[idx] = 0;  // No valid jump found
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return canReach(0, nums, dp);
}

// Driver code
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (canJump(nums) ? "true" : "false") << endl;  // Output: true

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << (canJump(nums2) ? "true" : "false") << endl;  // Output: false

    return 0;
}
