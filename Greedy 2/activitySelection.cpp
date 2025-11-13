#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2)
{
    return p1.second < p2.second;   // sort by finish time
}

int activitySelection(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    if (n == 0) return 0;

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({start[i], finish[i]});

    sort(v.begin(), v.end(), cmp);

    int ans = 1;
    int lastFinish = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (v[i].first > lastFinish) {
            ans++;
            lastFinish = v[i].second;
        }
    }

    return ans;
}

int main()
{
    vector<int> start = {1, 3, 2, 5};
    vector<int> finish = {2, 4, 3, 6};

    cout << activitySelection(start, finish);
    return 0;
}
