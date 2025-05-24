#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
vector<ssize_t> _dig = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
ssize_t dig(ssize_t n)
{
    if(_dig.size() <= n)_dig.resize(n+1, -1);
    
    if(_dig[n] == -1)_dig[n] = max(dig(n/10), n%10);
    return _dig[n];
}
 
vector<size_t> dp = {0};
size_t ans(size_t n)
{
    if(n == 0)return 0;
    if(dp.size() <= n)dp.resize(n+1, 0);
    if(dp[n] == 0)dp[n] = ans(n-dig(n))+1;
    return dp[n];
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n;
    cin >> n;
    cout << ans(n);
}
