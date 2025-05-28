#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

#define x second.first
#define y second.second
typedef pair<size_t, pair<ssize_t, size_t>> point;

void solve(size_t &n, size_t &m)
{
    size_t c;
    vector<vector<bool>> graph(n+2, vector<bool>(m+2,false));
    for (size_t i = 1; i <= n; i++)
    {
        for(size_t j = 1; j <= m; j++)
        {
            cin >> c;
            graph[i][j] = (c == 0);
        }
    }
    
    queue<point> bfs;
    bfs.push({0, {1, 1}});
    while (!bfs.empty())
    {
        auto &now = bfs.front();
        if(graph[now.x][now.y])
        {
            graph[now.x][now.y] = false;
            if(now.x == n && now.y == m)
            {
                cout << now.first << '\n';
                return;
            }
            
            for(auto &d :{1, -1})
            {
                bfs.push({now.first+1, {now.x, now.y+d}});
                bfs.push({now.first+1, {now.x+d, now.y}});
            }
        }
        bfs.pop();
    }
    cout << "Am I a joke to you?\n";
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, m;
    while(cin >> n >> m)
    {
        solve(n, m);   
    }
}