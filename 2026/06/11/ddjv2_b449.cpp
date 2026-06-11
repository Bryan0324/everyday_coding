#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull MOD = 1000000007;


void solve1(vector<ull> &a)
{
	ull ans = 0;
	sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++)
	{
		ans += a[i]*i %MOD;
		ans %=MOD;
	}
	cout << ans << '\n';
};

int merge_sort(int l, int r, vector<ull> &a)
{
	if(r-l <= 1)return 0;
	int mid = (l+r)/2;
	ull count = 0;
	count += merge_sort(l, mid, a);
	count %= MOD;
	count += merge_sort(mid, r, a);
	count %= MOD;
	
	vector<int> vl(mid - l), vr(r - mid);
	for(int i = 0; i < vl.size(); i++)vl[i] = a[i+l];
	for(int i = 0; i < vr.size(); i++)vr[i] = a[i+mid];
	vl.push_back(MOD+1);
	vr.push_back(MOD+1);
	for(int idx = l, l = 0, r = 0; l+1 < vl.size() || r+1 < vr.size(); idx++)
	{
		if(vl[l] <= vr[r] && l+1 < vl.size())a[idx] = vl[l++];
		else
		{
			a[idx] = vr[r++];
			count += vl.size()-l-1;
			count %= MOD;
		}
	}
	return count;
}

void solve2(vector<ull> &a)
{
	cout << merge_sort(0, a.size(), a);
};

void solve3(vector<ull> &a, ull p)
{
	for(auto &i : a)
	{
		ull cnt = 0;
		while(i % p == 0)
		{
			i /= p;
			cnt++;
		}
		i = cnt;
	}
	solve2(a);
};

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	ull n, op, p;
	cin >> n >> op;
	if(op == 3)cin >> p;
	
	vector<ull> a(n);
	for(auto &i : a)cin >> i;
	
	if(op == 1)solve1(a);
	else if(op == 2)solve2(a);
	else if(op == 3)solve3(a, p);
}
