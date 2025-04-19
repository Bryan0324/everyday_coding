#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000007;
vector<vector<size_t>> dp(1, vector<size_t>(2));
size_t solve()
{
    size_t n;
    cin >> n;
    if((n & 1) == 1)return 0;


    dp[0][0] = 1;
    dp[0][1] = 2;
    while(dp.size() <= n/2)
    {
        dp.push_back({0 ,0});
        auto i = dp.size()-1;
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][0] %= MOD;
        dp[i][1] = (dp[i-1][1] + (dp[i][0]*2)%MOD)%MOD;
        dp[i][1] %= MOD;

    }
    return dp[n/2][0];
}
int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    size_t t;
    cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}
/*
4
1 2 4 100000
*/
