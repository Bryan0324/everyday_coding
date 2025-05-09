#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

bool dfs(vector<ssize_t> &ans, ssize_t &now, ssize_t m, size_t cnt = 1)
{
	if(cnt == ans.size())return true;
	for(size_t i = 0; i < m; i++)
	{
		if(ans[now ^ (1ull << i)] == -1)
		{
			ans[now ^ (1ull << i)] = now;
			now ^= (1ull << i);
			if(dfs(ans, now, m, cnt+1))return true;
			now ^= (1ull << i);
			ans[now ^ (1ull << i)] = -1;
		}
	}
	return false;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ssize_t n, now = 0;
	cin >> n;
	vector<ssize_t> ans(1 << n, -1);
	ans[0] = -9;
	dfs(ans, now, n);
	while(now != -9)
	{
		for (int i = n-1; i >= 0; i--)
		{
			if((now&(1 << i)) != 0)cout << 1;
			else cout << 0;
		}
		cout << '\n';
		now = ans[now];
	}
}
