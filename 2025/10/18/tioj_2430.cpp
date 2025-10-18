#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    vector<ll> a(n), b(m);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1])dp[i][j] = max(dp[i][j], dp[i-1][j-1] + abs(i-j));
        }
    }
    cout << dp[n][m];
}