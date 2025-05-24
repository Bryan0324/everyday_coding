#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long
#define size_t unsigned long long

void solve()
{
    size_t n, m, s, e, f, a, b, c, d, cp;
    cin >> n >> m >> s >> e >> f;
    vector<vector<pair<size_t, size_t>>> graph(n+1);
    while(m--)
    {
        cin >> a >> b >> c >> d >> cp;
        if(f > d)c = c*d+cp*(f-d);
        else c = c*f;
        graph[a].push_back({c, b});
    }
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<>> pq;
    pq.push({0, s});
    vector<bool> visited(n+1, false);
    while(!pq.empty())
    {
        auto now = pq.top();
        cerr << now.first << ' ' << now.second << "]\n";
        if(now.second == e)break;
        pq.pop();
        if(visited[now.second])continue;
        visited[now.second] = true;
        for(auto &i : graph[now.second])pq.push({now.first+i.first, i.second});

    }
    cout << pq.top().first << '\n';
    return;
}


int main()
{
    size_t t;
    cin >> t;
    while(t--)solve();
}

