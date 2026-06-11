/**
* user:  user003
* fname: 
* lname: 黃柏諺
* task:  2026-fdpc-preliminary-andorxor
* score: 19.0
* date:  2026-06-10 06:14:05.849914
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> state;
#define X first.first
#define step first.second
#define pos second

typedef pair<pair<char, int>, int> path;

int count(int c, path p)
{
	switch (p.first.first)
	{
		case '^':
			return c ^ p.first.second;
		case '|':
			return c | p.first.second;
		case '&':
			return c & p.first.second;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<path>> graph(n);
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;
		char op;
		cin >> op;
		int c;
		cin >> c;
		graph[a].push_back({{op, c}, b});
		graph[b].push_back({{op, c}, a});
	}
	queue<state> bfs;
	vector<vector<int>> visited(n, vector<int>((1<<11)+1, -1));
	bfs.push({{0, 0}, 0});
	visited[0][0] = 0;
	while(!bfs.empty())
	{
		auto now = bfs.front();
		bfs.pop();
		for(auto &[opc, i] : graph[now.pos])
		{
			int next_x = count(now.X, {opc, i});
			if(visited[i][next_x] != -1)continue;
			visited[i][next_x] = now.step+1;
			bfs.push({{next_x, now.step+1}, i});
		}
	}
	for(int i = (1<<11); i >= 0; i--)
	{
		if(visited[n-1][i] != -1)
		{
			cout << visited[n-1][i];
			break;
		}
	}
}
