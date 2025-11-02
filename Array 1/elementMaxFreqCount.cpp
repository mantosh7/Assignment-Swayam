/*
3005. Count Elements With Maximum Frequency
You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

Example 1:
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
*/

#include <bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    int n = nums.size();
    if(n == 0 || n == 1) return n;

    int freq = 0;
    int maxi = 1;
    sort(nums.begin(), nums.end());

    int cnt = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) {
            cnt++;
        } else {
            if(cnt > maxi) {
                maxi = cnt;
                freq = 1;
            } else if(cnt == maxi) freq++;
            cnt = 1;
        }
    }

    if(cnt > maxi) {
        maxi = cnt;
        freq = 1;
    } else if(cnt == maxi) freq++;

    return maxi * freq;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << "Max frequency elements count: " << maxFrequencyElements(nums) << endl;
    return 0;
}
