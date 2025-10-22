#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

//const ull MOD = 1e9 + 7;

vector<ull> presum;
ull sum(int l, int r)
{
    return presum[r+1] - presum[l];
}

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<ull>> dp(n, vector<ull>(n, LLONG_MAX));
    vector<ull> a(n);
    presum = vector<ull>(n + 1);
    for(auto &i : a)cin >> i;
    for(int i = 1; i <= n; i++)
    {
        presum[i] = presum[i-1] + a[(i-1)];
        dp[i-1][i-1] = 0;
    }
    for(int s = 1; s < n; s++)
    {
        for(int i = 0; i < n-s; i++)
        {
            for(int mid = i; mid < i+s; mid++)dp[i][i+s] = min(dp[i][mid]+dp[mid+1][i+s], dp[i][i+s]);
            dp[i][i+s] += sum(i, i+s);
        }
    }
    
    cout << dp[0][n-1];
}


/* 環狀DP版本
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

//const ull MOD = 1e9 + 7;

vector<ull> presum;
ull sum(int l, int r)
{
    return presum[r+1] - presum[l];
}

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<ull>> dp(n*2, vector<ull>(n*2, LLONG_MAX>>1));
    vector<ull> a(n);
    presum = vector<ull>(n*2 + 1);
    for(auto &i : a)cin >> i;
    for(int i = 1; i <= n*2; i++)
    {
        presum[i] = presum[i-1] + a[(i-1)%n];
        dp[i-1][i-1] = 0;
    }
    for(int s = 1; s < n; s++)
    {
        for(int i = 0; i < n*2-s; i++)
        {
            for(int mid = i; mid < i+s; mid++)dp[i][i+s] = min(dp[i][mid]+dp[mid+1][i+s], dp[i][i+s]);
            dp[i][i+s] += sum(i, i+s);
        }
    }
    ull ans = LLONG_MAX;
    for(int i = 0; i <= n; i++)
    {
        ans = min(ans, dp[i][i+n-1]);
    }
    cout << ans;
}

*/