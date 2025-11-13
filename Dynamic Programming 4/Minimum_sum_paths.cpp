#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // dp[r][c] will store the minimum path sum to reach cell (r, c)
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Starting cell -> no choice, same as grid value
        dp[0][0] = grid[0][0];

        // Fill the first row (can only move right)
        for (int c = 1; c < cols; c++)
            dp[0][c] = dp[0][c - 1] + grid[0][c];

        // Fill the first column (can only move down)
        for (int r = 1; r < rows; r++)
            dp[r][0] = dp[r - 1][0] + grid[r][0];

        // Fill rest of the table
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                int bestPrev = min(dp[r - 1][c], dp[r][c - 1]); // from top or left
                dp[r][c] = bestPrev + grid[r][c];
            }
        }

        // Bottom-right cell has the answer
        return dp[rows - 1][cols - 1];
    }
};

// Driver Code
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum Path Sum: "
         << sol.minPathSum(grid) << endl;  
    // Expected Output: 7

    return 0;
}

/*
Time Complexity:  
    O(m * n)  → each cell processed once

Space Complexity:  
    O(m * n)  → DP table storage
*/
