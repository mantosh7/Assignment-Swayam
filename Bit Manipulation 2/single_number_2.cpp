#include <bits/stdc++.h>
using namespace std;

int singleNumber2(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int bitCount = 0;
        for (int x : nums) {
            if (x & (1 << i)) bitCount++;
        }
        if (bitCount % 3) {
            ans |= (1 << i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << singleNumber2(nums) << endl;
    return 0;
}
