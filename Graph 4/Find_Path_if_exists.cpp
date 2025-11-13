#include <bits/stdc++.h>
using namespace std;

/*
    DFS-based path checking in an undirected graph.

    The idea:
    - Build an adjacency list from the edge list.
    - Use DFS to explore nodes starting from 'src'.
    - If we reach 'dst' during DFS, a valid path exists.
*/

/*
    This DFS function tries to reach the destination from the current node.
    'curr'   = current node
    'dst'    = destination node we want to reach
    'graph'  = adjacency list
    'seen'   = marks visited nodes to avoid revisiting
*/
bool runDFS(int curr, int dst, vector<vector<int>>& graph, vector<bool>& seen) {
    if (curr == dst) return true;   // If we reach destination, path found.
    seen[curr] = true;              // Mark this node as visited

    // Explore all neighbors
    for (int nxt : graph[curr]) {
        if (!seen[nxt]) {
            if (runDFS(nxt, dst, graph, seen))
                return true;        // Path found in recursion
        }
    }
    return false;                   // No path found from this route
}

/*
    This function checks if a path exists between 'source' and 'destination'.
    It:
    - Builds adjacency list
    - Calls DFS
*/
bool pathExists(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);       // adjacency list

    // Build graph (undirected)
    for (auto& e : edges) {
        int a = e[0], b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> seen(n, false);        // visited array

    return runDFS(source, destination, graph, seen);
}

int main() {

    // Test Case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}};
    cout << "Test 1: "
         << (pathExists(n1, edges1, 0, 2) ? "true" : "false")
         << endl;

    // Test Case 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    cout << "Test 2: "
         << (pathExists(n2, edges2, 0, 5) ? "true" : "false")
         << endl;

    return 0;
}
