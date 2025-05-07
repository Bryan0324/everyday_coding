#include<bits/stdc++.h>
using namespace std;

struct pos : pair<size_t, size_t>
{
    size_t &a = this->first;
    size_t &b = this->second;
};

size_t solve()
{
    size_t n, m, lim;
    cin >> n >> m >> lim;
    vector<pos> ab(n);
    for(auto &i : ab)cin >> i.a >> i.b;
    vector<vector<size_t>> dp(lim+1, vector<size_t>(m+1, 0ull));
    for(size_t i = 0; i < n; i++)
    {
        for(size_t k = lim; k > 0; k--)
        {

            for(size_t j = m; j > 0; j--)
            {
                if(j >= ab[i].a)dp[k][j] = max(max(dp[k-1][j-ab[i].a] + ab[i].b, dp[k-1][j]), dp[k][j]);
                else dp[k][j] = max(dp[k-1][j], dp[k][j]);
            }
        }

    }
    size_t ans = 0;
    for(size_t i = 1; i <= lim; i++)if(ans < dp[i][m])ans = dp[i][m];
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    while(t--)cout << solve() << '\n';
}
/*

1
3 5 2
1 1
4 6
5 3
        for(auto &i : dp)
        {
            for(auto &j : i)cerr << j << ' ';
            cerr << '\n';
        }
        cerr << "=============================\n";
*/
