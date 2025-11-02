/*
Count Digits
Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.

Examples :
Input: n = 12
Output: 2
Explanation: 1, 2 when both divide 12 leaves remainder 0.
*/

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    int num = n;
    int cnt = 0;

    while (num != 0) {
        int rem = num % 10;
        if (rem != 0 && n % rem == 0) cnt++;
        num /= 10;
    }

    return cnt;
}

int evenlyDivides(int n) {
    return countDigits(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Count of digits that evenly divide " << n << ": " << evenlyDivides(n) << endl;

    return 0;
}
