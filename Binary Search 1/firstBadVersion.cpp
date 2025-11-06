/*
First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
*/

#include <bits/stdc++.h>
using namespace std;

int bad;

bool isBadVersion(int version) {
    return version >= bad;
}

int firstBadVersion(int n) {
    int ans = -1;
    int low = 1, high = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isBadVersion(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    bad = 4;
    int n1 = 5;
    cout << firstBadVersion(n1) << endl;
    
    bad = 1;
    int n2 = 1;
    cout << firstBadVersion(n2) << endl;
    
    bad = 1702766719;
    int n3 = 2126753390;
    cout << firstBadVersion(n3) << endl;
    
    return 0;
}