#include <bits/stdc++.h>
using namespace std;

// Wildcard matching problem
class Solution
{
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        int i = 0, j = 0, star = -1, match = 0;
        
        while (i < sLen) {
            if (j < pLen && (p[j] == s[i] || p[j] == '?')) {
                // Match single character or '?'
                i++; j++;
            } else if (j < pLen && p[j] == '*') {
                star = j++;     // Remember where star is
                match = i;      // Remember where we matched in s
            } else if (star != -1) {
                // If previous star exists, backtrack
                j = star + 1;
                i = ++match;
            } else {
                // If not match, and no star to backtrack, fail
                return false;
            }
        }
        // Skip remaining stars in pattern
        while (j < pLen && p[j] == '*') j++;
        return j == pLen;
    }
};


//Driver Code
int main()
{
    //3 testcases
    vector<string> a = {"aa", "aa", "cb"};
    vector<string> b = {"a", "*", "?a"};
    for (int i = 0; i < 3; ++i)
    {
        cout << (Solution().isMatch(a[i], b[i]) ? "true" : "false") << endl;
    }
    return 0;
}