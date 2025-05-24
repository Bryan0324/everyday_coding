#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000007;
vector<vector<vector<size_t>>> dp(3, vector<vector<size_t>>(3, vector<size_t>(2, 0)));
// red -> 0
// blue -> 1
// green -> 2
size_t solve()
{
    size_t n;
    cin >> n;
    while(dp[0][0].size() <= n)
    {
        auto i = dp[0][0].size()-1;
        for(size_t x = 0; x < 3; x++)
        {
            dp[x][0].push_back(dp[x][0][i]+dp[x][1][i]+dp[x][2][i]);
            dp[x][0].back() %= MOD;
            dp[x][1].push_back(dp[x][0][i]+dp[x][1][i]);
            dp[x][1].back() %= MOD;
            dp[x][2].push_back(dp[x][0][i]+dp[x][2][i]);
            dp[x][2].back() %= MOD;
        }

    }
    return (dp[0][0][n]+dp[0][1][n]+dp[0][2][n] +dp[1][0][n]+dp[1][1][n] +dp[2][0][n]+dp[2][2][n]) %MOD;
}
int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    size_t t;
    for(size_t x = 0; x < 3; x++)dp[x][x][1] = 1;
    cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}
/*
4
1 2 3 100000
*/

