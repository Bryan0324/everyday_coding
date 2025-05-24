#include <bits/stdc++.h>
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
 
	deque<size_t> window;
	size_t ans = 0;
	vector<size_t> xs = {x};
	for(size_t i = 0; i < k-1; i++, xs.push_back((xs.back()*a + b) %c))
	{
		while(!window.empty())
		{
			if(xs[window.back()] > xs[i])window.pop_back();
			else break;
		}
		window.push_back(i);
	}
	for (size_t i = k-1; i < n; i++, xs.push_back((xs.back()*a + b) %c))
	{
		if(i-window.front()+1 > k)window.pop_front();
		while(!window.empty())
		{
			if(xs[window.back()] > xs[i])window.pop_back();
			else break;
		}
		window.push_back(i);
		ans ^= xs[window.front()];
	}
	cout << ans;
	
}
