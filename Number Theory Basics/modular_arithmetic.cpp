#include <bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) return -1;
    int num = 1, len = 1;
    set<int> seen;
    while (num % k != 0) {
        num = (num * 10 + 1) % k;
        len++;
        if (seen.count(num)) return -1;
        seen.insert(num);
    }
    return len;
}

int main() {
    int k;
    cin >> k;
    cout << smallestRepunitDivByK(k) << endl;
    return 0;
}
