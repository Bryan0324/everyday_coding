#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

typedef pair<size_t, size_t> edge;
#define weight first
#define to second

struct djset
{
	vector<size_t> tt;
	djset(size_t n)
	{
		tt = vector<size_t>(n);
		for(size_t i = 0; i < n; i++)tt[i] = i;
	}
	size_t find(size_t x)
	{
		if(tt[x] == x)return x;
		tt[x] = find(tt[x]);
		return tt[x];
	}
	void join(size_t a, size_t b)
	{
		a = tt[a]; b = tt[b];
		tt[b] = a;
	}
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t n, m, a, b, w;
	cin >> n >> m;
	djset ds(n);
	vector<__gnu_pbds::priority_queue<edge, greater<>>> e(n);
	vector<size_t> point(n);
	for(auto &i : point)cin >> i;
	
	while (m--)
	{
		cin >> a >> b >> w;
		--a; --b;
		e[a].push({w, b});
		e[b].push({w, a});
	}
	for (size_t i = 0; i < n; i++)e[i].push({LLONG_MAX, LLONG_MAX});
	size_t price = 0, cnt = 0;
	for (ssize_t i = 0; i < n; i++)
	{
		if(point[i] == 0 || e[i].size() == 0)continue;
		if(point[i] < e[i].top().weight)
		{
			price += point[i];
			point[i] = 0;
			continue;
		}
		auto now = ds.find(e[i].top().to);
		if(now == ds.find(i))
		{
			e[i].pop();
			--i;
			continue;
		}
		price += e[i].top().weight;
		point[now] = min(point[i], point[now]);
		ds.join(ds.find(e[i].top().to), i);
		e[ds.find(e[i].top().to)].join(e[i]);
	}
	cout << price;
}


/* 

5 6
6 4 6 2 3
1 1 4
3 5 3
2 3 1
1 4 3
2 3 1 
5 3 5


9 10
3 1 4 1 5 9 2 6 5
3 1 4
1 5 9
2 6 5
3 5 8
9 7 9
3 2 3
8 4 6
2 6 4
3 3 8
3 2 7
*/