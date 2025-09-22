#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;
 
const ll INF = LONG_LONG_MIN/2;
 
vector<vector<ll>> dp;
vector<int> x;
vector<ll> pre;
ll best(int l, int r)
{
    if(dp[l][r] != INF)return dp[l][r];
    if(l+1 == r)return x[l];
    dp[l][r] = pre[r] - pre[l] - min(best(l+1, r), best(l, r-1));
    return dp[l][r];
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
    dp = vector<vector<ll>>(n+1, vector<ll>(n+1, INF));
    x = vector<int>(n);
    pre = vector<ll>(n+1);
    for(auto &i : x)cin >> i;
    
    for (size_t i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + x[i-1];
    }
    cout << best(0, n);
}
