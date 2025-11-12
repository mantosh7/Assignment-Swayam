#include <bits/stdc++.h>
using namespace std;

int toggleBitsInRange(int n, int l, int r) {
    int mask = 0;
    for (int i = l; i <= r; i++) {
        mask |= (1 << (i - 1));
    }
    return n ^ mask;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << toggleBitsInRange(n, l, r) << endl;
    return 0;
}
