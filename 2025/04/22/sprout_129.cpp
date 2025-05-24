#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;

size_t solve()
{
	size_t n;
	cin >> n;
	vector<size_t> a(n+1);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    
	vector<vector<size_t>> dp(n, vector<size_t>(n, 1e7));
    for (size_t i = 0; i < n; i++)dp[i][i] = 0;
    
	for(size_t d = 1; d < n; d++)
	{
		for(size_t i = 0; i < n-d; i++)
		{
            for(size_t now = i; now < i+d; now++)dp[i][i+d] = min(dp[i][i+d], dp[i][now]+dp[now+1][i+d]);
            dp[i][i+d] += a[i+d+1]-a[i];
        }
	}
	return dp[0][n-1];
}
int main()
{
	size_t t;
    cin.tie(0)->sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cout << solve() << '\n';
	}
}
/* 

*/
