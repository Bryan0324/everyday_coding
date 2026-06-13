#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &i : a)cin >> i;
	vector<ll> pre_sum(n+1);
	for(int i = 1; i <= n; i++)
	{
		pre_sum[i] = pre_sum[i-1]+a[i-1];
		pre_sum[i] %= n;
		pre_sum[i] += n;
		pre_sum[i] %= n;
	}

	map<ll, ll> s;
	ll ans = 0;
	for(int i = 0; i < n+1; i++)
	{
		ans += s[pre_sum[i]];
		s[pre_sum[i]]++;
	}
	cout << ans;
}
