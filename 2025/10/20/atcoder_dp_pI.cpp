#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<double> p(n);
    for(auto &i : p)cin >> i;
    vector<vector<double>> dp(2, vector<double>(n+1));
    dp[0][0] = 1;
    double ans = 0;
    for(int i = 1; i <= n; i++)dp[0][i] = dp[0][i-1] * (1.-p[i-1]);
    for(int i = 1; i <= n; i++)
    {
        dp[i & 1][0] = 0;
        for(int j = 1; j <= n; j++)
        {
            dp[i & 1][j] = dp[i & 1][j-1]*(1.-p[j-1]) + dp[(i-1) & 1][j-1]*p[j-1];
        }
        if(i > n/2)ans += dp[i & 1][n];
    }
    cout << fixed << setprecision(10) << ans;
}


/* 
非滾動陣列
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<double> p(n);
    for(auto &i : p)cin >> i;
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)dp[0][i] = dp[0][i-1] * (1.-p[i-1]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j-1]*(1.-p[j-1]) + dp[i-1][j-1]*p[j-1];
        }
    }
    double ans = 0;
    for (int i = n/2 + 1; i <= n; i++)
    {
        ans += dp[i][n];
    }
    cout << fixed << setprecision(10) << ans;
}
*/