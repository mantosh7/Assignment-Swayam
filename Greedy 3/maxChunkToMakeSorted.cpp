#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
        if (maxi == i)
            cnt++;
    }
    
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxChunksToSorted(arr);
    return 0;
}
