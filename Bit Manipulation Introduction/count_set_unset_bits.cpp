#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    if (n == 0) return 0;

    int x = log2(n);
    int bitsTill2x = x * (1 << (x - 1));
    int msbRest = n - (1 << x) + 1;
    int rest = countSetBits(n - (1 << x));
    
    return bitsTill2x + msbRest + rest;
}

int main() {
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    return 0;
}
