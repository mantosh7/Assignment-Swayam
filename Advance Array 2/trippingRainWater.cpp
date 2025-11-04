/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> maxLeft(n), maxRight(n);

    maxLeft[0] = height[0];
    for (int i = 1; i < n; i++)
        maxLeft[i] = max(maxLeft[i - 1], height[i]);

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxRight[i] = max(maxRight[i + 1], height[i]);

    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(maxLeft[i], maxRight[i]) - height[i];

    return water;
}

int main() {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height);
    return 0;
}
