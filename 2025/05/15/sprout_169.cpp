#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t k, n;
	cin >> n >> k;
	vector<ssize_t> suffix(n);
	for(auto &i : suffix)cin >> i;
	for(size_t i = n-1; i > 0; i--)
	{
		suffix[i-1] += suffix[i];
	}
	vector<ssize_t> dp(n+1, LLONG_MIN/2);
	dp[n] = 0;
	deque<size_t> window;
	window.push_back(n);
	for (ssize_t i = n-1; i >= 0; i--)
	{
		if(window.front()-i > k)window.pop_front();
		dp[i] = dp[window.front()] + suffix[i];
		while(!window.empty())
		{
			if(dp[window.back()] > dp[i])break;
			window.pop_back();
		}
		window.push_back(i);
		//cerr << dp[i] - suffix[i] << ' ';
	}
	cout << dp[0] - suffix[0];
}
