/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    for(int i = n - k, j = n - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
    }

    for(int i = 0, j = n - k - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
    }

    for(int i = 0, j = n - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
    }
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter rotation count k: ";
    cin >> k;

    rotate(nums, k);

    cout << "Array after rotation: ";
    for(int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
