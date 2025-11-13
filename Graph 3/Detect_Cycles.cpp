#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int v, const vector<vector<int>> &adj, vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, adj, visited, v))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, const vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj = {
        {1, 2},
        {0, 2},
        {0, 1}
    };

    if (hasCycle(V, adj))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found in the graph.\n";

    return 0;
}
