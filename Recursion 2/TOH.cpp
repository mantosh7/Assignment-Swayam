/*
Tower Of Hanoi

*/

#include <bits/stdc++.h>
using namespace std;

int TOH(int n, int src, int helper, int dst) {
    if (n == 1) return 1;
    return 1 + TOH(n - 1, src, dst, helper) + TOH(n - 1, helper, src, dst);
}

int towerOfHanoi(int n, int from, int to, int aux) {
    return TOH(n, from, aux, to);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Total moves required: " << towerOfHanoi(n, 1, 3, 2) << endl;
    return 0;
}
