#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = dp[0][1] = a[0];
    dp[0][1] += b[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(a[i], dp[i-1][0]+a[i]);
        dp[i][1] = max(dp[i][0]+b[i], dp[i-1][1]+a[i]);
    }
    ll ans = dp[0][0];
    for(auto &i : dp)ans = max(ans, i[k & 1]);
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

