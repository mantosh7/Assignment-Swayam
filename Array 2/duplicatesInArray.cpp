/*
442. Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range 
[1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) ans.push_back(abs(nums[i]));
        else nums[index] = -nums[index];
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = findDuplicates(nums);

    cout << "Duplicate elements: ";
    for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
