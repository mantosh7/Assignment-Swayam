#include <bits/stdc++.h>
using namespace std;

int minPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int n = arr.size();

    int i = 0, j = 0;
    int ans = INT_MIN;
    int platform = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platform++;
            i++;
        } else {
            platform--;
            j++;
        }
        ans = max(ans, platform);
    }
    return ans;
}

int main() {
    int n;
    cin >> n; // Number of trains

    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // Arrival times
    for (int i = 0; i < n; i++) cin >> dep[i]; // Departure times

    cout << minPlatform(arr, dep);
    return 0;
}
