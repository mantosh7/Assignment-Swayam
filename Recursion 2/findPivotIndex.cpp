/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/

#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& nums, int leftSum, int totalSum, int idx) {
    if (idx == nums.size()) return -1;
    if (leftSum == totalSum - leftSum - nums[idx]) return idx;

    return findPivot(nums, leftSum + nums[idx], totalSum, idx + 1);
}

int pivotIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    for (int num : nums) totalSum += num;
    return findPivot(nums, leftSum, totalSum, 0);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = pivotIndex(nums);
    cout << "Pivot index: " << ans << endl;

    return 0;
}
