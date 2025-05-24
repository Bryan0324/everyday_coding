#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long


int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t n, k;
	cin >> n >> k;
	size_t x, a, b, c;
	cin >> x >> a >> b >> c;
	pair<size_t, size_t> ptr;
	ptr.first = ptr.second = x;
	size_t window = x;
	for(size_t i = 2; i <= k; i++)
	{
		ptr.second = (ptr.second*a+b) %c;
		window ^= ptr.second;
	}
	size_t ans = window;
	for(size_t i = k+1; i <= n; i++)
	{
		window ^= ptr.first;
		ptr.first = (ptr.first*a+b) %c;
		ptr.second = (ptr.second*a+b) %c;
		window ^= ptr.second;
		ans ^= window;
	}
	cout << ans;
}

