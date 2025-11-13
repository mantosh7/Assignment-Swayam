#include <bits/stdc++.h>
using namespace std;

// DFS to explore one whole province
void explore(int city, vector<vector<int>>& mat, vector<int>& seen) {
    seen[city] = 1;

    for (int nxt = 0; nxt < mat.size(); nxt++) {
        if (mat[city][nxt] == 1 && !seen[nxt]) {
            explore(nxt, mat, seen);
        }
    }
}

// Counts connected groups of cities (provinces)
int countProvinces(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> seen(n, 0);
    int groups = 0;

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            groups++;
            explore(i, mat, seen);
        }
    }
    return groups;
}

int main() {
    vector<vector<int>> g1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << "Provinces: " << countProvinces(g1) << endl;

    vector<vector<int>> g2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Provinces: " << countProvinces(g2) << endl;

    return 0;
}
