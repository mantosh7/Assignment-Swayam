/*
Reverse The Array
Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.

*/

#include<bits/stdc++.h>
using namespace std;

void reverseAfterM(vector<int>& arr, int m) {
    if(m < 0 || m >= arr.size() - 1) {
        return;
    }
    reverse(arr.begin() + m + 1, arr.end());
}

int main() {
    int n, m;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position M: ";
    cin >> m;

    reverseAfterM(arr, m);

    cout << "Array after reversing after position " << m << ": ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
