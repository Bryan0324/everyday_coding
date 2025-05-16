#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t k, n, x, a, b, c;
	cin >> n >> k;
	cin >> x >> a >> b >> c;
	queue<size_t> win;
	win.push(x);
	size_t now = x, sum = x;
	for(size_t it = 1; it < k; it++)
	{
		now = (now*a+b)%c;
		win.push(now);
		sum += now;
	}
	size_t ans = sum;
	for(size_t i = k+1; i <= n; i++)
	{
		sum -= win.front();
		win.pop();
		now = (now*a+b)%c;
		win.push(now);
		sum += now;
		ans ^= sum;
	}
	cout << ans;
}
