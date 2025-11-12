#include <bits/stdc++.h>
using namespace std;

int countZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> prefixCount;
    int prefixSum = 0;
    int count = 0;

    prefixCount[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixCount.find(prefixSum) != prefixCount.end()) {
            count += prefixCount[prefixSum];
        }
        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << countZeroSumSubarrays(arr);
    return 0;
}
