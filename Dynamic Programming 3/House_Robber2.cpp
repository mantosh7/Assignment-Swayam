#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Compute max loot from a linear segment of houses
    int solveRange(vector<int>& nums, int left, int right) {
        int prev = 0;     // dp[i-2]
        int curr = 0;     // dp[i-1]

        for (int i = left; i < right; i++) {
            int bestBefore = curr;
            int take = prev + nums[i];   // loot this house
            curr = max(curr, take);      // best so far
            prev = bestBefore;           // shift window
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Only one house → must take it
        if (n == 1) return nums[0];

        // Because houses are circular:
        // Case 1 → include first, exclude last (0 ... n-2)
        // Case 2 → exclude first, include last (1 ... n-1)
        int option1 = solveRange(nums, 0, n - 1);
        int option2 = solveRange(nums, 1, n);

        return max(option1, option2);
    }
};

int main() {
    Solution s;

    vector<int> a1 = {2, 3, 2};
    cout << "Max loot (circular): " << s.rob(a1) << endl;   // 3

    vector<int> a2 = {1, 2, 3, 1};
    cout << "Max loot (circular): " << s.rob(a2) << endl;   // 4

    vector<int> a3 = {1, 2, 3};
    cout << "Max loot (circular): " << s.rob(a3) << endl;   // 3

    return 0;
}

/*
Time Complexity:  O(n)
Space Complexity: O(1)
*/
