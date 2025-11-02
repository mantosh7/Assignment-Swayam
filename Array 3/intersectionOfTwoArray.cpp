/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int i = 0, j = 0;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } 
        else if (nums2[j] < nums1[i]) {
            j++;
        } 
        else {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    vector<int> ans = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
