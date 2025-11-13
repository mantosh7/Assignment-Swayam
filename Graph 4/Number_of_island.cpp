#include <bits/stdc++.h>
using namespace std;

// DFS that explores one complete connected component
void explore(int node, vector<vector<int>>& graph, vector<bool>& seen) {
    seen[node] = true;

    for (int nxt : graph[node]) {
        if (!seen[nxt]) {
            explore(nxt, graph, seen);
        }
    }
}

// Counts total connected components in an undirected graph
int countComponents(int n, vector<vector<int>>& edges) {

    // adjacency list creation
    vector<vector<int>> graph(n);
    for (auto &e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]); 
    }

    vector<bool> seen(n, false);
    int components = 0;

    // for every unvisited node, run DFS and mark one full component
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            components++;
            explore(i, graph, seen);
        }
    }
    return components;
}

int main() {

    // Example 1
    int n1 = 5;
    vector<vector<int>> e1 = {{0,1}, {1,2}, {3,4}};
    cout << "Islands: " << countComponents(n1, e1) << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> e2 = {{0,1}, {2,3}};
    cout << "Islands: " << countComponents(n2, e2) << endl;

    // Example 3
    int n3 = 4;
    vector<vector<int>> e3 = {{0,1}, {1,2}, {2,3}};
    cout << "Islands: " << countComponents(n3, e3) << endl;

    return 0;
}
