#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1000007;
vector<vector<size_t>> _c = {{1}, {1}};

size_t c(size_t n, size_t m)//, string space = "")
{
    //cout << space << 'C' << n << ' ' << m << '\n';
    if(n < m)return 0;
    if(m > n/2)m = n-m;
    while(_c.size() <= n)
    {
        _c.push_back(vector<size_t>(_c.size()/2+1, 0));
    }
    if(m == 0)_c[n][m] = 1;
    else if(_c[n][m] == 0)_c[n][m] = (c(n-1, m-1)+c(n-1, m)) %MOD;
    //cout << space << _c[n][m] << '\n';
    return _c[n][m];
}

size_t solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<size_t> a(n);
	for(auto &i : a)cin >> i;
	
	vector<vector<size_t>> dp(n+1, vector<size_t>(m+1));
	dp[0][0] = 1;
	for(size_t l = 1; l <= n; l++)
	{
		for(size_t h = 1; h <= m; h++)
		{
			auto &k = a[l-1];
			if(h >= k)for(size_t i = 0; i <= k; i++)
			{
				dp[l][h] += c(h-i, k-i)*c(m-h+i, i)%MOD*dp[l-1][h-i]%MOD;
                dp[l][h] %= MOD;
                //cout << '[' << dp[l][h] << '\n';
			}
		}
	}
    return dp[n][m];
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
11 4

*/
