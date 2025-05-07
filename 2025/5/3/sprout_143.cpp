#include<bits/stdc++.h>
using namespace std;

struct pos : pair<size_t, size_t>
{
    size_t &a = this->first;
    size_t &b = this->second;
};

size_t solve()
{
    size_t n, m;
    cin >> n >> m;
    vector<pos> ab(n);
    for(auto &i : ab)cin >> i.a >> i.b;
    vector<size_t> dp(m+1);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = m; j >= ab[i].a; j--)
        {
            if(dp[j-ab[i].a] + ab[i].b > dp[j])dp[j] = dp[j-ab[i].a] + ab[i].b;
        }
    }
    return dp[m];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    while(t--)cout << solve() << '\n';
}
