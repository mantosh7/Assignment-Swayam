#include <bits/stdc++.h>
using namespace std;

// Find parent (with path compression)
int findSet(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent[x], parent);
}

// Merge two sets by rank
void joinSet(int a, int b, vector<int>& parent, vector<int>& rankv) {
    a = findSet(a, parent);
    b = findSet(b, parent);

    if (a == b) return;

    if (rankv[a] < rankv[b]) {
        parent[a] = b;
    } else if (rankv[a] > rankv[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankv[a]++;
    }
}

// Kruskal algorithm for MST
int kruskal(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [&](auto& x, auto& y) {
        return x[2] < y[2];
    });

    vector<int> parent(n), rankv(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int weight = 0, used = 0;

    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];

        if (findSet(u, parent) != findSet(v, parent)) {
            joinSet(u, v, parent, rankv);
            weight += w;
            used++;

            cout << "Taking edge: " << u << " - " << v << "  cost: " << w << endl;

            if (used == n - 1) break;
        }
    }
    return weight;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    int ans = kruskal(n, edges);
    cout << "Total MST weight = " << ans << endl;

    return 0;
}
