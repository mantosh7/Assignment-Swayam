#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(n + 1, INF);
        vector<int> used(n + 1, 0);
        priority_queue<pair<int,int>> pq;  // storing {-distance, node}

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            pair<int,int> topElem = pq.top();
            pq.pop();

            int negd = topElem.first;
            int node = topElem.second;
            int d = -negd;                // original distance value

            if (used[node]) continue;
            used[node] = 1;

            for (size_t i = 0; i < adj[node].size(); ++i) {
                int to = adj[node][i].first;
                int wt = adj[node][i].second;

                if (dist[node] + wt < dist[to]) {
                    dist[to] = dist[node] + wt;
                    pq.push(make_pair(-dist[to], to));
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<vector<pair<int,int>>> adj(n + 1);

    adj[1].push_back(make_pair(2, 2));
    adj[1].push_back(make_pair(3, 5));
    adj[2].push_back(make_pair(3, 4));
    adj[2].push_back(make_pair(4, 4));
    adj[3].push_back(make_pair(4, 3));
    adj[3].push_back(make_pair(5, 1));
    adj[4].push_back(make_pair(5, 2));

    int source = 1;
    vector<int> dist = sol.dijkstra(n, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}

/*
Time Complexity:
    O((V + E) log V)

Space Complexity:
    O(V + E)
*/
