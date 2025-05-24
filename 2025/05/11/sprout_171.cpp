#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

size_t solve()
{
	size_t n, a;
	cin >> n;
	vector<vector<size_t>> dp(1ull << n, vector(n, (size_t)LLONG_MAX));
	for (size_t i = 0; i < n; i++)
	{
		dp[(1ull << i)][i] = 0;
		for (size_t j = i+1; j < n; j++)
		{
			cin >> a;
			dp[(1ull << i) | (1ull << j)][j] = a;
			dp[(1ull << j) | (1ull << i)][i] = a;
		}
	}
	for(size_t i = 1; i < dp.size(); i++)
	{
		if((i & (1 << 0)) == 0)continue;
		for(size_t j = 1; j < n; j++)
		{
			if((i & (1 << j)) == 0)
			{
				for (size_t k = 1; k < n; k++)
				{
					dp[i ^ (1ull<<j)][j] = min(dp[i ^ (1ull<<j)][j], dp[i][k]+dp[(1ull<<k) | (1ull<<j)][j]);
				}
			}
		}
	}
	size_t ans = LLONG_MAX;
	auto &now = dp.back();
/* 	for(size_t idx = 0; idx < dp.size(); idx++)
	{
		auto &i = dp[idx];
		for(auto &j : i)cout << (j == LLONG_MAX ? "X" : to_string(j)) << ' ';
		
		string debug = "";
		size_t tmp = idx;
		while(tmp != 0)
		{
			debug += ((tmp&1) == 0 ? "0" : "1");
			tmp >>= 1;
		}
		while(debug.size() != n)debug += "0";
		cout << debug;
		cout << '\n';
	} */
	for(size_t i = 1; i < n; i++)
	{
		ans = min(ans, now[i]+dp[(1ull<<i) | (1ull<<0)][0]);
	}
	return ans;
}
int main()
{
  cin.tie(0)->sync_with_stdio(false);
  size_t t;
	cin >> t;
	while(t--)cout << solve() << '\n';

}
