/*
Implement Upper Bound
Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

Example :
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
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

    int index = upperBound(arr, target);

    if (index < arr.size())
        cout << "Upper bound index: " << index << ", value: " << arr[index] << endl;
    else
        cout << "Upper bound index: " << index << " (target >= all elements)" << endl;

    return 0;
}
