#include <bits/stdc++.h>
using namespace std;

// Function to compute number of set bits for all numbers from 0 to n
vector<int> countBits(int n) {

    // Result array where res[i] = number of 1s in binary of i
    vector<int> res(n + 1, 0);

    // Use DP relation: res[i] = res[i/2] + (i % 2)
    for (int i = 1; i <= n; i++) {
        res[i] = res[i >> 1] + (i & 1);  
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    vector<int> out = countBits(n);

    for (int x : out)
        cout << x << " ";

    return 0;
}
