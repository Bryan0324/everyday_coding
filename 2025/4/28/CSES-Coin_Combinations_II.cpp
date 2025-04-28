#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n, x;
    cin >> n >> x;
    vector<size_t> c(n);
    for(auto &i : c)cin >> i;
    sort(c.begin(), c.end());
    vector<size_t> dp(x+1, 0ull);
    dp[0] = 1;
    for(size_t i = 1; i <= n; i++)
    {
        for(size_t j = c[i-1]; j <= x; j++)
        {
            dp[j] += dp[j-c[i-1]];
            dp[j] %= MOD;
        }
    }
    cout << dp[x];
}
