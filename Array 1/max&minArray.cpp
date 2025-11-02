/*
2091. Removing Minimum and Maximum From Array
You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

Example 1:
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minEle = nums[0], maxEle = nums[0];
        int minIdx = 0, maxIdx = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] < minEle) {
                minEle = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxEle) {
                maxEle = nums[i];
                maxIdx = i;
            }
        }

        if(minIdx > maxIdx) swap(minIdx, maxIdx);

        int op1 = maxIdx + 1;
        int op2 = n - minIdx;
        int op3 = (minIdx + 1) + (n - maxIdx);

        return min({op1, op2, op3});
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.minimumDeletions(nums);

    cout << "Minimum deletions required: " << result << endl;
    return 0;
}
