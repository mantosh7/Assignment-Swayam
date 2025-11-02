/*
Sum of Array
You are given an integer array arr[]. The task is to find the sum of it.
*/

#include <bits/stdc++.h>
using namespace std;

int findSum(vector<int>& arr, int idx) {
    if (idx == arr.size()) return 0;
    return arr[idx] + findSum(arr, idx + 1);
}

int arraySum(vector<int>& arr) {
    return findSum(arr, 0);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Sum of array elements: " << arraySum(arr) << endl;

    return 0;
}
