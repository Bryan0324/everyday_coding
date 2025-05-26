#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    size_t n, m;
    cin >> n >> m;
    vector<size_t> a(n), b(m);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;

    vector<vector<size_t>> dp(n+1, vector(m+1, 0ull));
    for(size_t i = 1; i <= n; i++)
    {
        for(size_t j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    vector<size_t> ans;
    while(dp[n][m] != 0)
    {
        if(dp[n-1][m-1] == dp[n][m])
        {
            --n; --m;
        }else if(dp[n-1][m] == dp[n][m])--n;
        else if(dp[n][m-1] == dp[n][m])--m;
        else
        {
            ans.push_back(a[--n]);
            --m;
        }
    }
    while (!ans.empty())
    {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    
}
/* 
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4

*/