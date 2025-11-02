/*
53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = nums[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum > maxi) maxi = sum;
        if (sum < 0) sum = 0;
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
