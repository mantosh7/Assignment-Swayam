#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& students, vector<int>& cookies) {
    int n = students.size();
    int m = cookies.size();

    sort(students.begin(), students.end());
    sort(cookies.begin(), cookies.end());

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (cookies[j] >= students[i]) {
            i++;
        }
        j++;
    }
    return i;
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<int> students(n), cookies(m);
    for (int i = 0; i < n; i++) cin >> students[i];
    for (int j = 0; j < m; j++) cin >> cookies[j];

    cout << findContentChildren(students, cookies) << endl;
    return 0;
}
