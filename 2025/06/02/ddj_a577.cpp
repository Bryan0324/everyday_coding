#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    unordered_set<size_t> shell;
    unordered_map<size_t, unordered_map<size_t, size_t>> graph;

    size_t n, m, k, r;
    cin >> n >> m >> k >> r;
    size_t tmp;
    while(k--)
    {
        cin >> tmp;
        shell.insert(tmp);
    }
    size_t u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        if(shell.find(u) != shell.end())u = 0;
        if(shell.find(v) != shell.end())v = 0;
        if(u != v)
        {
            if(graph[u].find(v) == graph[u].end())graph[u][v] = graph[v][u] = w;
            else graph[u][v] = graph[v][u] = min(graph[u][v], w);
        }
    }
    vector<bool> visited(n+1, false);
    vector<size_t> cnt;
    __gnu_pbds::priority_queue<pair<size_t, size_t>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if(visited[now.second])continue;
        visited[now.second] = true;
        cnt.push_back(now.first);
        for(auto &i : graph[now.second])
        {
            if(!visited[i.first])
            {
                pq.push({now.first+i.second, i.first});
                graph[i.first].erase(now.second);
            }
        }
    }
    cout << cnt[cnt.size()-1-r];
}