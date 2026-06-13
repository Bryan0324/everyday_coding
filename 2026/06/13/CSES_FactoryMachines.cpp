#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	ull n, t;
	cin >> n >> t;
	vector<ull> k(n);
	for(auto &i : k)cin >> i;

	ull ans = 1e18+1;
	for(ull l = 0, &r = ans; r-l > 1; )
	{
		ull mid = (l+r)/2, cnt = 0;
		for(auto &i : k)
		{
			cnt += mid/i;
			if(cnt >= t)break;
		}
		if(cnt >= t)r = mid;
		else l = mid;
	}
	cout << ans;
}
