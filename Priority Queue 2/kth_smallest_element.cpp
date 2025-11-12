#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) minHeap.push(num);

    for (int i = 1; i < k; i++) minHeap.pop();

    return minHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << findKthSmallest(nums, k) << endl;
    return 0;
}
