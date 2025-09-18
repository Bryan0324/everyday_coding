#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pos;
#define x first
#define y second

unordered_map<char, Pos> ways = {
    {'R', {0, 1}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
};
Pos operator+(Pos &a, Pos &b)
{
    return {a.x+b.x, a.y+b.y};
}
Pos operator-(Pos &a, Pos &b)
{
    return {a.x-b.x, a.y-b.y};
}

typedef pair<char, Pos> bfs_unit;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n+2, vector<char>(m+2, '!'));
    Pos start;
    queue<bfs_unit> bfs;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 'M')bfs.push({'M', {i, j}});
            else if(graph[i][j] == 'A')start = {i, j};
        }
    }
    bfs.push({'A', start});
    vector<vector<char>> visited = graph;
    
    while(!bfs.empty())
    {
        auto &[ch, top] = bfs.front();
        if(ch == 'A' && graph[top.x][top.y] == '!')break;
        if(graph[top.x][top.y] == '!')
        {
            bfs.pop();
            continue;
        }
        for(auto &d : ways)
        {
            auto next = top + d.second;
            if(visited[next.x][next.y] == '.' || visited[next.x][next.y] == '!')
            {
                visited[next.x][next.y] = d.first;
                if(ch == 'M')
                {
                    visited[next.x][next.y] = 'M';
                    bfs.push({ch, next});
                }else
                {
                    visited[next.x][next.y] = d.first;
                    bfs.push({ch, next});
                }
                
            }
        }
        bfs.pop();
    }
    if(bfs.empty())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    string ans;
    auto now = bfs.front().second;
    while(start != now)
    {
        ans.push_back(visited[now.x][now.y]);
        now = now - ways[visited[now.x][now.y]];
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    cout << ans.size() << '\n';
    cout << ans;
}