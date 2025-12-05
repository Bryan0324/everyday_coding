#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0, lest = 0;
    for(auto &i : s)
    {
        if(i == '0' && lest == 0)ans++;
        if(lest > 0)lest--;
        if(i == '1')lest = k;
    }
    cout << ans << '\n';
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

