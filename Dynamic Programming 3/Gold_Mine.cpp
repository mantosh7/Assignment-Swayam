#include <bits/stdc++.h>
using namespace std;

// Recursive helper to compute max gold from (r, c)
int dfs(int r, int c, vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();

    // If out of bounds → no gold possible
    if (r < 0 || r >= n || c >= m)
        return 0;

    // Explore three possible moves
    int upRight    = dfs(r - 1, c + 1, grid);
    int rightMove  = dfs(r,     c + 1, grid);
    int downRight  = dfs(r + 1, c + 1, grid);

    // Select maximum gold from the three directions
    return grid[r][c] + max({upRight, rightMove, downRight});
}

// Main function to compute max gold collectable from any starting row
int maxGold(vector<vector<int>> &grid) {

    int n = grid.size();
    int best = 0;

    // Try starting from each row in column 0
    for (int row = 0; row < n; row++) {
        best = max(best, dfs(row, 0, grid));
    }

    return best;
}

int main() {

    vector<vector<int>> grid = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };

    cout << maxGold(grid);

    return 0;
}
