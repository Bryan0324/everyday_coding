#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long
 
const size_t MOD = 1e9+7;
 
size_t _dp[501][501] = {0};
 
size_t &dp(size_t i, size_t j)
{
    if(i > j)return dp(j, i);
    
    if(i == j && _dp[i][j] == 0)return _dp[i][j];
    else if(_dp[i][j] == 0)_dp[i][j] = LLONG_MAX;
    else return _dp[i][j];
    for(size_t cut = 1; cut < i; cut++)
    {
        _dp[i][j] = min(_dp[i][j], dp(i-cut, j)+dp(cut, j)+1);
    }
    for(size_t cut = 1; cut < j; cut++)
    {
        _dp[i][j] = min(_dp[i][j], dp(i, j-cut)+dp(i, cut)+1);
    }
    return _dp[i][j];
}
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    size_t a, b;
    cin >> a >> b;
    cout << dp(a, b);
}