#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size(), k = p.size();
    if (n < k) return ans;

    vector<int> cntP(26, 0), cntS(26, 0);

    for (char ch : p) cntP[ch - 'a']++;

    for (int i = 0; i < n; i++) {
        cntS[s[i] - 'a']++;

        if (i >= k) cntS[s[i - k] - 'a']--;

        if (i >= k - 1 && cntS == cntP)
            ans.push_back(i - k + 1);
    }
    return ans;
}

int main() {
    string s, p;
    cin >> s >> p;

    vector<int> res = findAnagrams(s, p);
    for (int idx : res) cout << idx << " ";
    cout << endl;
    return 0;
}
