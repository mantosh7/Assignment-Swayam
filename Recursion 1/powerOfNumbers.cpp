/*
Given a number n, find the value of n raised to the power of its own reverse.
Note: The result will always fit into a 32-bit signed integer.
*/

#include <bits/stdc++.h>
using namespace std;

int findPower(int num, int x) {
    if (x == 0) return 1;
    if (x == 1) return num;

    if (x % 2 == 0)
        return findPower(num * num, x / 2);
    return num * findPower(num * num, x / 2);
}

int reverseExponentiation(int n) {
    int x = 0;
    int num = n;

    while (num != 0) {
        int rem = num % 10;
        x = x * 10 + rem;
        num /= 10;
    }

    return findPower(n, x);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = reverseExponentiation(n);
    cout << "Result (n raised to reverse(n)): " << result << endl;

    return 0;
}
