#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            visited[x][y] == 0 && maze[x][y] == 1);
}

void solveMaze(vector<vector<int>>& maze, int n, int x, int y,
               vector<vector<int>>& visited, string path, vector<string>& ans) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, n, visited, maze))
        solveMaze(maze, n, x + 1, y, visited, path + 'D', ans);

    // Left
    if (isSafe(x, y - 1, n, visited, maze))
        solveMaze(maze, n, x, y - 1, visited, path + 'L', ans);

    // Right
    if (isSafe(x, y + 1, n, visited, maze))
        solveMaze(maze, n, x, y + 1, visited, path + 'R', ans);

    // Up
    if (isSafe(x - 1, y, n, visited, maze))
        solveMaze(maze, n, x - 1, y, visited, path + 'U', ans);

    visited[x][y] = 0;
}

vector<string> findPaths(vector<vector<int>>& maze, int n) {
    vector<string> ans;
    if (maze[0][0] == 0) return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    solveMaze(maze, n, 0, 0, visited, "", ans);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cout << "Enter size of maze (n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<string> result = findPaths(maze, n);

    if (result.empty())
        cout << "No path found!\n";
    else {
        cout << "\nAll possible paths:\n";
        for (auto& p : result)
            cout << p << endl;
    }
    return 0;
}
