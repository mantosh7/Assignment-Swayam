#include <bits/stdc++.h>
using namespace std;

int gcd_int(int x, int y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    while (y) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd_int(a, b) * b;
}

int inclusionExclusion(int n, int a, int b, int c) {
    int ab = lcm(a, b);
    int bc = lcm(b, c);
    int ac = lcm(a, c);
    int abc = lcm(a, bc);
    int res = n / a + n / b + n / c
              - n / ab - n / bc - n / ac
              + n / abc;
    return res;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << inclusionExclusion(n, a, b, c) << endl;
    return 0;
}
