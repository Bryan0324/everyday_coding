#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9 + 7;

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto &i : a)for(auto &j : i)cin >> j;
    vector<int> dp(1<<n);
    dp[0] = 1;
    for (int mask = 0; mask < 1<<n; mask++)
    {
        int cnt = __builtin_popcount(mask);
        for (int i = 0; i < n; i++)
        {
            if(!(mask & (1<<i)) && a[cnt][i] == 1)
            {
                dp[mask | (1<<i)] += dp[mask];
                dp[mask | (1<<i)] %= MOD;
            }
        }
    }
    cout << dp[(1<<n) - 1];
}

