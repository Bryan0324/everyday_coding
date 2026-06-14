#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	ll n, k;
	cin >> n >> k;
	k--;
	vector<ll> a(n);
	for(auto &i : a)cin >> i;

	vector<ll> pre_sum(n+1);
	for(ll i = 1; i <= n; i++)pre_sum[i] = a[i-1]+pre_sum[i-1];

	ll ans = pre_sum[n]-pre_sum[0];
	if(k != 0)for(ll l = 0, &r = ans, now_k = k; r-l > 1; now_k = k)
	{
		ll mid = (l+r)/2;
		int prev = 0;
		for(int i = 1; i <= n; i++)
		{
			if(pre_sum[i]-pre_sum[prev] <= mid)continue;
			prev = i-1;
			if(--now_k == 0 || a[i-1] > mid)break;
		}
		if(pre_sum[n]-pre_sum[prev] <= mid)r = mid;
		else l = mid;
	}
	cout << ans;
}
