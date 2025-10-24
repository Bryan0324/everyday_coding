#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9 + 7;
const ll INF_low = LLONG_MIN;

int n, k, m;
void set_turnable(int level, vector<vector<bool>> &turnable, vector<vector<bool>> &passable, vector<vector<int>> &masks)
{
    for (int i = 0; i < turnable.size(); i++)
    {
        for (int j = 0; j < turnable[i].size(); j++)
        {
            turnable[i][j] = false;
        }
    }
    turnable[0][0] = true;
    for(int cnt = 1; cnt <= k; cnt++)
    {
        for(auto &mask1 : masks[cnt])
        {
            for(auto &mask2 : masks[cnt])
            {
                int u = __lg((-mask1) & mask1);
                for(int v = 0; v < k; v++)
                {
                    if(!(mask2 & (1<<v)))continue;
                    
                    if(passable[level*k + u][(level-1)*k + v])
                    {
                        turnable[mask1][mask2] = turnable[mask1 ^ (1<<u)][mask2 ^ (1<<v)];
                        if(turnable[mask1][mask2])break;
                    }
                }
            }
        }
    }
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k >> m;
    vector<vector<int>> a(n, vector<int>(k));
    for(auto &j : a)for(auto &i : j)cin >> i;

    vector<vector<bool>> passable(n*k, vector<bool>(n*k));

    int u, v;
    while(m--)
    {
        cin >> u >> v;
        u--; v--;
        passable[u][v] = true;
        passable[v][u] = true;
    }

    vector<vector<int>> masks(k+1);
    for (int i = 0; i < 1<<k; i++)
    {
        masks[__builtin_popcount(i)].push_back(i);
    }
    
    vector<vector<bool>> turnable((1<<k)+1, vector<bool>((1<<k)+1));
    
    vector<vector<ll>> dp(n, vector<ll>((1<<k), INF_low));
    for (int i = 0; i < n; i++)
    {
        if(i != 0)set_turnable(i, turnable, passable, masks);
        for(int cnt = 1; cnt <= k; cnt++)
        {
            for(auto &mask1 : masks[cnt])
            {
                if(i != 0)for(auto &mask2 : masks[cnt])
                {
                    if(turnable[mask1][mask2])dp[i][mask1] = max(dp[i-1][mask2], dp[i][mask1]);
                }
                if(i == 0)dp[i][mask1] = 0;
                for(int bit = 0; bit < k; bit++)
                {
                    if((mask1 >> bit) & 1)if(dp[i][mask1] != INF_low)dp[i][mask1] += a[i][bit];
                }
            }
            
        }
    }
    
    for(int cnt = 1; cnt <= k; cnt++)
    {
        ll ans = -1;
        for(auto mask : masks[cnt])ans = max(ans, dp[n-1][mask]);
        cout << ans << ' ';
    }
}
