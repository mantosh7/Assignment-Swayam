#include <bits/stdc++.h>
using namespace std;

// DFS to explore all possible gold-collection paths
int explore(vector<vector<int>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();

    // Out of bounds or no gold left
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
        return 0;

    int currGold = grid[x][y];
    grid[x][y] = 0;   // Mark as visited

    // Move in 4 directions
    int left  = explore(grid, x, y - 1);
    int right = explore(grid, x, y + 1);
    int up    = explore(grid, x - 1, y);
    int down  = explore(grid, x + 1, y);

    grid[x][y] = currGold;   // Backtrack: restore gold

    // Best path + current gold
    return currGold + max(max(left, right), max(up, down));
}

int getMaximumGold(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int best = 0;

    // Try starting DFS from every gold cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > 0) {
                best = max(best, explore(grid, i, j));
            }
        }
    }
    return best;
}

int main() {
    vector<vector<int>> grid1 = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };

    cout << "Max gold: " << getMaximumGold(grid1) << endl;  // 24

    vector<vector<int>> grid2 = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    cout << "Max gold: " << getMaximumGold(grid2) << endl;  // 28

    return 0;
}

/*
Time Complexity:  O((n * m) * 4^(n*m))   worst-case DFS exploration
Space Complexity: O(n * m) recursion + backtracking
*/
