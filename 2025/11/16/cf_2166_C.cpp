#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

struct DSU
{
	vector<int> boss, val, _l, _r;
	DSU(int n)
	{
		_l = _r = boss = val = vector<int>(n, 1);
		for(int i = 0; i < n; i++)boss[i] = _l[i] = _r[i] = i;
	}
	int query(int q)
	{
		if(boss[q] != q)boss[q] = query(boss[q]);
		return boss[q];
	}
	void merge(int a, int b)
	{
		a = query(a); b = query(b);
		boss[b] = a;
		val[a] = max(val[a], val[b]);
		_r[a] = _r[b];
	}
	int cost(int a)
	{
		return val[query(a)];
	}
	int l(int a)
	{
		return _l[query(a)];
	}
	int r(int a)
	{
		return _r[query(a)];
	}
};


typedef pair<int, int> pq_unit;
#define c first
#define idx second
void solve()
{
	int n;
	cin >> n;
	DSU djs(n);
	for(auto &i : djs.val)cin >> i;
	priority_queue<pq_unit, vector<pq_unit>, greater<pq_unit>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push({djs.val[i], i});
	}
	ull cost = 0;
	ull k = n-1;
	while(!pq.empty() && k > 0)
	{
		auto top = pq.top();
		pq.pop();
		if(djs.query(top.idx) != top.idx || djs.cost(top.idx) != top.c)continue;
		if(djs.cost((djs.l(top.idx)+n-1)%n) < djs.cost((djs.r(top.idx)+1)%n))
		{
			djs.merge((djs.l(top.idx)+n-1)%n, top.idx);
		}else
		{
			djs.merge(top.idx, (djs.r(top.idx)+1)%n);
		}
		pq.push({djs.cost(top.idx), top.idx});
		cost += djs.cost(top.idx);
		k--;
	}
	cout << cost << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}