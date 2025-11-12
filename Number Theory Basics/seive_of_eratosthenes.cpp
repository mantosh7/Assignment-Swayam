#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = 2 * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;
    return 0;
}
