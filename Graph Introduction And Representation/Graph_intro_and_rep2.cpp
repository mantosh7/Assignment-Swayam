#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
    int V = 5;

    vector<vector<int>> adj(V, vector<int>(V, 0));

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    cout << "ADJACENCY MATRIX REPRESENTATION\n";
    cout << "---------------------------------\n\n";

    cout << "    ";
    for (int j = 0; j < V; ++j)
        cout << j << " ";
    cout << "\n";

    cout << "    ";
    for (int j = 0; j < V; ++j)
        cout << "--";
    cout << "\n";

    for (int i = 0; i < V; ++i) {
        cout << i << " | ";
        for (int j = 0; j < V; ++j)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
