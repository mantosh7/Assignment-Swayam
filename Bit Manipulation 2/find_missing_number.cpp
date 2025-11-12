#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++)
        ans ^= i ^ nums[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << missingNumber(nums) << endl;
    return 0;
}
