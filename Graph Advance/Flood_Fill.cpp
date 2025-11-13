#include <bits/stdc++.h>
using namespace std;

// DFS to recolor connected region
void fillDFS(int r, int c, int oldColor, int newColor, vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Out of bounds OR not the target color → stop
    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != oldColor)
        return;

    // Change the current cell color
    grid[r][c] = newColor;

    // Explore neighbors
    fillDFS(r + 1, c, oldColor, newColor, grid);
    fillDFS(r - 1, c, oldColor, newColor, grid);
    fillDFS(r, c + 1, oldColor, newColor, grid);
    fillDFS(r, c - 1, oldColor, newColor, grid);
}

// Wrapper function
vector<vector<int>> floodPaint(vector<vector<int>>& grid, int sr, int sc, int color) {
    int target = grid[sr][sc];

    // If the color is already same, skip DFS
    if (target != color)
        fillDFS(sr, sc, target, color, grid);

    return grid;
}

int main() {
    vector<vector<int>> img = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> out = floodPaint(img, sr, sc, newColor);

    cout << "After flood fill:\n";
    for (auto &row : out) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
