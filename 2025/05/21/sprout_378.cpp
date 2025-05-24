#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second

typedef pair<size_t, size_t> edge;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    size_t n, m, q, a, b, w;
    cin >> n >> m >> q;
    vector<vector<edge>> graph(n);
    vector<vector<edge>> dis_graph(n);
    while(m--)
    {
        cin >> a >> b >> w;
        --a; --b;
        graph[a].push_back(edge({w, b}));
        dis_graph[b].push_back(edge({w, a}));
    }
    vector<bool> visited(n, false);
    priority_queue<edge, vector<edge>, greater<>> pq;
    vector<size_t> from_start(n, LLONG_MAX), to_end(n, LLONG_MAX);
    pq.push(edge({0, 0}));
    while(!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if(visited[now.to])continue;
        visited[now.to] = true;
        from_start[now.to] = now.weight;
        for(auto &i : graph[now.to])if(!visited[i.to])pq.push(edge({i.weight+now.weight, i.to}));
    }
    visited = vector(n, false);
    pq.push(edge({0, n-1}));
    while(!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if(visited[now.to])continue;
        visited[now.to] = true;
        to_end[now.to] = now.weight;
        for(auto &i : dis_graph[now.to])if(!visited[i.to])pq.push(edge({i.weight+now.weight, i.to}));
    }
    while(q--)
    {
        cin >> a >> b;
        --a; --b;
        cout << min(to_end[0], from_start[a]+1+to_end[b]) << '\n';
    }
}
/* 
6 5 3
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
2 5
1 6
3 2


*/
