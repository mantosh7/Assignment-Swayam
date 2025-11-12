#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k) {
    return (n & (1 << (k - 1))) != 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (isKthBitSet(n, k))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
