#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

const ll BIT = 1;
const ll INF = LLONG_MIN/2;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<vector<vector<ll>>>> dp(min(33ll, k+1), vector(33, vector(2, vector(2, INF))));

    for(int now = 0; now < 33; now++)dp[0][now][n>>now&BIT][0] = 0;
    for(int dk = 1; dk < dp.size(); dk++)
    {
        for(int now = 0; now < 33; now++)
        {
            bool ori = n>>now&BIT;
            if(now)if(ori)
            {
                dp[dk][now][0][1] = max({
                    dp[dk][now-1][0][1]+1,
                    dp[dk][now-1][1][1]+1,
                });
                dp[dk][now][1][0] = max({
                    dp[dk][now-1][1][0],
                    dp[dk][now-1][0][0],
                });
                dp[dk][now][1][1] = dp[dk-1][now-1][0][1]+1;
            }else
            {
                dp[dk][now][1][0] = max({
                    dp[dk][now-1][1][1],
                    dp[dk][now-1][0][1],
                });
                dp[dk][now][0][0] = max({
                    dp[dk][now-1][0][0],
                    dp[dk][now-1][1][0],
                });
            }

            dp[dk][now][0][1] = max({
                dp[dk][now][0][1],
                dp[dk-1][now][1][0]+1,
            });
            dp[dk][now][1][0] = max({
                dp[dk][now][1][0],
                dp[dk-1][now][0][0],
            });
            dp[dk][now][1][1] = max({
                dp[dk][now][1][1],
                dp[dk-1][now][0][1],
                dp[dk-1][now][1][0]+1,
            });
        }
    }
    ll ans = 0;
    for(int dk = 1; dk < dp.size(); dk++)
    {
        for(auto &i : dp[dk][32])
        {
            for(auto &j : i)ans = max(ans, j+k-dk);
        }
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}