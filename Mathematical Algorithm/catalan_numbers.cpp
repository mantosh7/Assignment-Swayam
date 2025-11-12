#include <bits/stdc++.h>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int nodes = 2; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
    return 0;
}
