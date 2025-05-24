#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(auto &i : c)cin >> i;
    sort(c.begin(), c.end());
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++)
    {
        for(auto &j : c)
        {
            if(j > i)break;
            if(dp[i-j] == INT_MAX)continue;
            if(dp[i] > dp[i-j]+1)dp[i] = dp[i-j]+1;
        }
    }
    if(dp[x] != INT_MAX)cout << dp[x];
    else cout << -1;
}
