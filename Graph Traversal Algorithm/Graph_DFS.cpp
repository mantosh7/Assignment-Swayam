#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int x : adj[node])
        if (!visited[x])
            dfsUtil(x, adj, visited);
}

void dfsTraversal(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    dfsUtil(start, adj, visited);
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int x : adj[i]) cout << x << " ";
        cout << endl;
    }
    cout << endl;

    dfsTraversal(0, adj, V);

    return 0;
}
