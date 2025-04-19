#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
size_t solve()
{
    size_t n;
    cin >> n;
    vector<size_t> dp(n), a(n);
    for(auto &i : a)cin >> i;
    if(n == 1)return a[0];
    dp[0] = a[0];
    dp[1] = max(a[1], a[0]);
    for (size_t i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-2]+a[i], dp[i-1]);
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
