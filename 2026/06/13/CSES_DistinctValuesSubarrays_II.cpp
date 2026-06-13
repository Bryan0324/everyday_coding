#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto &i : a)cin >> i;
	
	map<ll, ll> cnt;
	ull ans = 0;
	for(int l = 0, r = 0, now = 0; r < n; r++)
	{
		if(cnt[a[r]]++ == 0)now++;
		for(; now > k; l++)
		{
			if(--cnt[a[l]] == 0)now--;
		}
		ans += r-l+1;
	}
	cout << ans;
}
