#include <bits/stdc++.h>
using namespace std;

/*
    Prim's MST using Min-Heap

    Time Complexity:  O((V + E) log V)
    Space Complexity: O(V + E)
*/

int primMST(int n, vector<vector<pair<int,int>>>& graph) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> used(n, 0);
    int totalWeight = 0;
    int countUsed = 0;

    pq.push(make_pair(0, 0));  // weight, node

    cout << "Edges selected in MST:\n";

    while (!pq.empty() && countUsed < n) {

        pair<int,int> topElement = pq.top();
        pq.pop();

        int w = topElement.first;
        int u = topElement.second;

        if (used[u]) continue;

        used[u] = 1;
        totalWeight += w;
        countUsed++;

        if (w != 0) {
            cout << "Take node " << u << " with cost " << w << "\n";
        }

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (!used[v]) {
                pq.push(make_pair(wt, v));
            }
        }
    }

    return totalWeight;
}

int main() {
    int n = 4;
    vector<vector<pair<int,int>>> graph(n);

    graph[0].push_back({1,10});
    graph[0].push_back({2,6});
    graph[0].push_back({3,5});

    graph[1].push_back({0,10});
    graph[1].push_back({3,15});

    graph[2].push_back({0,6});
    graph[2].push_back({3,4});

    graph[3].push_back({0,5});
    graph[3].push_back({1,15});
    graph[3].push_back({2,4});

    int result = primMST(n, graph);
    cout << "\nTotal MST Weight = " << result << "\n";

    return 0;
}
