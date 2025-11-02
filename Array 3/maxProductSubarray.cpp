/*
152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int currMax = nums[0];
    int currMin = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0)
            swap(currMax, currMin);

        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        ans = max(ans, currMax);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = maxProduct(nums);
    cout << "Maximum product subarray: " << result << endl;

    return 0;
}
