/*
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int count = 1;
    int length = nums.size();
    for(int j = 1; j < length; j++) {
        if(nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    int k = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    cout << "New length: " << k << endl;

    return 0;
}
