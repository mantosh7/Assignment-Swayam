#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counter;
    for (int n : nums) {
        counter[n]++;
    }

    vector<vector<int>> freq(nums.size() + 1);
    for (auto& entry : counter) {
        freq[entry.second].push_back(entry.first);
    }

    vector<int> res;
    for (int i = freq.size() - 1; i >= 0; i--) {
        for (int num : freq[i]) {
            res.push_back(num);
            if (res.size() == k) {
                return res;
            }
        }
    }

    return {};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = topKFrequent(nums, k);

    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}
