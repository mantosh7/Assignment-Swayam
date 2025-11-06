/*
Implement Lower Bound
Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

Examples :
Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> arr = {1, 3, 3, 5, 8, 10, 12};
    int target;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nEnter target: ";
    cin >> target;

    int index = lowerBound(arr, target);

    if (index < arr.size())
        cout << "Lower bound index: " << index << ", value: " << arr[index] << endl;
    else
        cout << "Lower bound index: " << index << " (target greater than all elements)" << endl;

    return 0;
}
