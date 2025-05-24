#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
size_t solve()
{
    size_t n, k;
    cin >> n >> k;
    vector<size_t> dp(n), a(n);
    for(auto &i : a)cin >> i;
    if(n == 1)return a[0];
    dp[0] = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if(k > i)dp[i] = max(a[i], dp[i-1]);
        else dp[i] = max(dp[i-k]+a[i], dp[i-1]);
    }
    return dp[n-1];
}
int main()
{
    size_t t;
    cin >> t;
    cin.tie(0)->sync_with_stdio(false);
    while(t--)
    {
        cout << solve() << '\n';
    }
}

/* 
*/
