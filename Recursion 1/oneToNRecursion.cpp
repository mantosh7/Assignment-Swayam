/*
Print 1 to n without using loops

Given an positive integer n, print numbers from 1 to n without using loops.

Implement the function printTillN() to print the numbers from 1 to n as space-separated integers.
*/


#include <bits/stdc++.h>
using namespace std;

void printTillN(int n) {
    if (n == 0) return;     
    printTillN(n - 1);     
    cout << n << " ";   
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": ";
    printTillN(n);
    cout << endl;

    return 0;
}
