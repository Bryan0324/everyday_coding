/**
* user:  user003
* fname: 
* lname: 黃柏諺
* task:  2026-fdpc-preliminary-interview
* score: 100.0
* date:  2026-06-10 05:10:54.113162
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(auto &i : a)cin >> i;
	for(auto &i : b)cin >> i;
	
	int ans = 0;
	
	for(int i = 0, l, r; i < m; i++)
	{
		cin >> l >> r;
		bool exp = false;
		for(int i = l; i < r; i++) 
		{
			if(a[i-1] > a[i])
			{
				exp = true;
				break;
			}
		}
		for(int i = l-1; i < r; i++)
		{
			if(a[i] < b[i])
			{
				exp = true;
				break;
			}
		}
		if(exp)ans++;
	}
	cout << ans;
}
