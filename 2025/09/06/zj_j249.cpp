#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> Pos;
#define x first
#define y second
vector<Pos> ways = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}
};

Pos operator+(const Pos &a, const Pos &b)
{
    return {a.x + b.x, a.y + b.y};
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ull m, n, p, q;
    Pos target, tp;
    cin >> m >> n;
    cin >> p >> q;
    cin >> target.y >> target.x;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4)));
    while(p--)
    {
        cin >> tp.y >> tp.x;
        visited[tp.x][tp.y] = vector<bool>(4, true);
    }
    while(q--)
    {
        cin >> tp.y >> tp.x;
        graph[tp.x][tp.y] = -2;
    }
    queue<pair<pair<Pos, int>, int>> bfs;
    bfs.push({{{0, 0}, -4}, 0});
    while(!bfs.empty())
    {
        auto &[now, from] = bfs.front().first;
        auto &cnt = bfs.front().second;
        if(now.x == target.x && now.y == target.y)break;
        for (int i = 0; i < 4; i++)
        {
            if((from+3) % 4 == i && graph[now.x][now.y] == -2)continue;
            if((from+2) % 4 == i)continue;
            auto tmp = now + ways[i];
            if(tmp.x >= n || tmp.x < 0)continue;
            if(tmp.y >= m || tmp.y < 0)continue;
            if(visited[tmp.x][tmp.y][i])continue;

            if(graph[tmp.x][tmp.y] == -2)visited[tmp.x][tmp.y][i] = true;
            else visited[tmp.x][tmp.y] = vector<bool>(4, true);
            bfs.push({{tmp, i}, cnt+1});
        }
        bfs.pop();
    }
    cout << bfs.front().second;
}