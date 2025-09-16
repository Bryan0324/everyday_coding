#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

typedef pair<int, int> Pos;
#define x first
#define y second
Pos operator+(const Pos a, const Pos b)
{
    return {a.x+b.x, a.y+b.y};
}

typedef pair<ull, Pos> bfs_unit;
#define val first
#define p second

vector<Pos> ways = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>> graph(n+2, vector<char>(m+2, 'Y'));
    queue<bfs_unit> bfs;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] != 'Y')cnt++;
            if(graph[i][j] == 'Z')bfs.push({1, {i, j}});
            
        }   
    }
    while(cnt)
    {
        auto &top = bfs.front();
        if(graph[top.p.x][top.p.y] != 'Y')
        {
            graph[top.p.x][top.p.y] = 'Y';
            cnt--;
        }else 
        {
            bfs.pop();
            continue;
        }
        if(cnt == 0)break;
        for(auto &d : ways)
        {
            auto tmp = top.p + d;
            if(graph[tmp.x][tmp.y] != 'Y')
            {
                bfs.push({top.val+1, tmp});
            }
        }
        bfs.pop();
    }
    cout << bfs.front().val;
}
