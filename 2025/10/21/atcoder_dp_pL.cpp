#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
vector<vector<ull>> _dp;
vector<ll> presum;

ull sum(int l, int r)
{
    return presum[r+1] - presum[l];
}

ull dp(int l, int r)
{
    if(_dp[l][r] == 0)_dp[l][r] = max(sum(l, r) - dp(l, r-1), sum(l, r) - dp(l+1, r));
    return _dp[l][r];
}
int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ull> a(n);
    for(auto &i : a)cin >> i;
    presum = vector<ll>(n+1);
    _dp = vector<vector<ull>>(n, vector<ull>(n));

    for (int i = 1; i <= n; i++)
    {
        _dp[i-1][i-1] = a[i-1];
        presum[i] = presum[i-1] + a[i-1];
    }
    ll x = dp(0, n-1);
    ll y = presum[n] - x;
    cout << x - y;
}