#include <bits/stdc++.h>
using namespace std;

// Recursive + Memoized function to compute minimum jumps
int minJumps(int idx, vector<int>& nums, vector<int>& dp) {
    int n = nums.size() - 1;

    // If we reached the last index → 0 jumps needed
    if (idx == n) 
        return 0;

    // If we jump beyond array → invalid large number
    if (idx > n)
        return 1e9;

    // DP memoization check
    if (dp[idx] != -1)
        return dp[idx];

    int best = 1e9;

    // Try all possible jumps from current index
    for (int jump = 1; jump <= nums[idx]; jump++) {
        int subAns = minJumps(idx + jump, nums, dp);
        if (subAns != 1e9)
            best = min(best, 1 + subAns);
    }

    return dp[idx] = best;
}

int jumpGame(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);

    return minJumps(0, nums, dp);
}

// Driver code
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};  
    cout << "Minimum jumps required: " << jumpGame(nums) << endl; // Output: 2

    vector<int> nums2 = {2, 1, 0, 3};  
    cout << "Minimum jumps (case 2): " << jumpGame(nums2) << endl; // Output: large number (unreachable)

    return 0;
}
