#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long



int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t n, m, u, v, w;
	cin >> n >> m;
	vector<vector<pair<size_t, size_t>>> graph(n);
	while (m--)
	{
		cin >> u >> v >> w;
		--u;--v;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}
	vector<size_t> visited(n, false);
	size_t cnt = 0, ans = 0;
	priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<>> pq;
	pq.push({0, 0});

	while(!pq.empty())
	{
		pair<size_t, size_t> now = pq.top();
		while(visited[now.second])
		{
			pq.pop();
			now = pq.top();
		}
		//cerr << now.first << ' ' << now.second << '\n';
		ans += now.first;
		if(++cnt == n)break;
		visited[now.second] = true;
		pq.pop();
		for(auto &i : graph[now.second])pq.push(i);
	}
	cout << ans;
}
