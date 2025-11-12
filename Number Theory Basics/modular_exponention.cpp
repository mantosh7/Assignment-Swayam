#include <bits/stdc++.h>
using namespace std;
const int MOD = 1337;

int powerMod(int a, int k) {
    a %= MOD;
    int res = 1;
    for (int i = 0; i < k; i++)
        res = (res * a) % MOD;
    return res;
}

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int lastDigit = b.back();
    b.pop_back();
    int part1 = powerMod(superPow(a, b), 10);
    int part2 = powerMod(a, lastDigit);
    return (part1 * part2) % MOD;
}

int main() {
    int a, n;
    cin >> a >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    cout << superPow(a, b) << endl;
    return 0;
}
