/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example:
Input: nums = [3,0,1]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int firstnsum = (n * (n + 1)) / 2;

    int numsSum = 0;
    for (int i = 0; i < n; i++) {
        numsSum += nums[i];
    }
    return firstnsum - numsSum;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums) << endl;
    return 0;
}
