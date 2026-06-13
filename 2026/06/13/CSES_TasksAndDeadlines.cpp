#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	ull n;
	cin >> n;
	
	ll d = 0;
	vector<ll> f(n);
	for(auto &i : f)
	{
		ll b;
		cin >> i >> b;
		d += b;
	}
	sort(f.begin(), f.end());
	for(int i = 0; i < n; i++)
	{
		d -= f[i]*(n-i);
	}
	cout << d;
}
