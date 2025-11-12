#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> firstSeen;
    int prefixSum = 0;
    int maxLen = 0;

    firstSeen[0] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (firstSeen.find(prefixSum) != firstSeen.end()) {
            int prevIndex = firstSeen[prefixSum];
            int length = i - prevIndex;
            maxLen = max(maxLen, length);
        } 
        else {
            firstSeen[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << maxLength(arr);
    return 0;
}
