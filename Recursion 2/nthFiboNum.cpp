/*
Nth Fibonacci Number
Given a non-negative integer n, your task is to find the nth Fibonacci number.

The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

The Fibonacci sequence is defined as follows:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) for n > 1

Examples :

Input: n = 5
Output: 5
Explanation: The 5th Fibonacci number is 5.
*/

#include <bits/stdc++.h>
using namespace std;

int findFibo(int n, int secondLast, int last) {
    if (n == 0) return secondLast;
    if (n == 1) return last;
    return findFibo(n - 1, last, last + secondLast);
}

int nthFibonacci(int n) {
    return findFibo(n, 0, 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << n << "th Fibonacci number: " << nthFibonacci(n) << endl;
    return 0;
}
