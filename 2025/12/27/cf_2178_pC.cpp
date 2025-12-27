#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, m, a;
    cin >> n >> m;

    
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert({a, i+1});
    }
    vector<pair<int, int>> ans;
    while(s.size() != m)
    {
        ans.push_back({s.begin()->first, next(s.end(), -1)->first});
        auto tmp = *next(s.end(), -1);
        tmp.second -= s.begin()->second;
        s.erase(s.begin());
        s.erase(next(s.end(), -1));
        s.insert(tmp);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        solve();   
    }
}