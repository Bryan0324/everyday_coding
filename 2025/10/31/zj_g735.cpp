#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> rank(n);
    vector<pair<int, int>> s(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first;
        s[i].second = i;
        cnt[s[i].first]++;
    }
    sort(s.begin(), s.end(), greater<>());
    s.push_back({INT_MIN, n});
    for (int i = 0, nrank = 1; i < n; i++)
    {
        rank[s[i].second] = nrank;
        if(s[i].first != s[i+1].first)nrank += cnt[s[i].first];
    }
    for(auto &i : rank)cout << i << ' ';

}