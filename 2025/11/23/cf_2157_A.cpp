#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    unordered_map<int, int> m;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    for(auto &i : v)m[i]++;
    int ans = 0;
    for(auto &i : m)
    {
        if(i.first != i.second)
        {
            if(i.first > i.second)ans += i.second;
            else ans += i.second - i.first;
        }
    }
    cout << ans << '\n';
    return;
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