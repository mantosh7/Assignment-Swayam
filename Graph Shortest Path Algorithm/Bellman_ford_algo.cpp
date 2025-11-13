#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        // distance array: start with infinite distance
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int step = 1; step <= V - 1; step++) {

            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                // Only relax if u is reachable
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycle
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Negative Cycle Found\n";
                return {};   // return empty list
            }
        }

        return dist;
    }
};

int main() {

    Solution obj;

    int V = 5;

    // {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 11},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, 13}
    };

    int source = 0;

    vector<int> dist = obj.bellmanFord(V, edges, source);

    if (!dist.empty()) {
        cout << "Shortest distance from node " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) 
                cout << "Node " << i << ": INF\n";
            else
                cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
