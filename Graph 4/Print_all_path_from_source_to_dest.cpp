#include <bits/stdc++.h>
using namespace std;

// DFS that records every possible route from node 0 to node (n-1)
void explorePaths(int curr, vector<vector<int>>& adj, vector<int> route, vector<vector<int>>& result, int target) {
    route.push_back(curr);

    // If we reached the last node, store the route
    if (curr == target) {
        result.push_back(route);
        return;
    }

    // Try all next possible moves
    for (int nxt : adj[curr]) {
        explorePaths(nxt, adj, route, result, target);
    }
}

// Wrapper to generate all paths from source (0) to destination (last node)
vector<vector<int>> getAllPaths(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> result;
    vector<int> route;

    explorePaths(0, adj, route, result, n - 1);
    return result;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    vector<vector<int>> paths = getAllPaths(graph);

    cout << "All paths from source to target:\n";
    for (auto& p : paths) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }

    return 0;
}
