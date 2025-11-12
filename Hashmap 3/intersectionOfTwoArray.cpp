/*
Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, bool> mp;
    vector<int> ans;

    for (int x : nums1)
        mp[x] = true;           // mark present in nums1

    unordered_set<int> st;      // to avoid duplicates

    for (int x : nums2) {
        if (mp[x])              // if x was in nums1
            st.insert(x);       // insert uniquely
    }

    return vector<int>(st.begin(), st.end());
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> res = intersection(nums1, nums2);

    for (int x : res) cout << x << " ";
    return 0;
}
