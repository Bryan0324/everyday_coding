#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pos;
#define x first
#define y second
typedef pair<int, Pos> pq_uint;
#define val first
#define p second
vector<Pos> ways = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}
};
vector<vector<int>> ori;
int dfs(vector<vector<int>> &graph, int i, int j, int w)
{
    int ans = w-ori[i][j];
    for(auto &d : ways)
    {
        if(graph[i+d.x][j+d.y] == 0)
        {
            graph[i+d.x][j+d.y] = -1;
            ans += dfs(graph, i+d.x, j+d.y, w);
        }
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n+2, vector<int>(m+2, -1));
    priority_queue<pq_uint, vector<pq_uint>, greater<>> pq;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            pq.push({graph[i][j], {i, j}});
        }
    }
    ori = graph;
    queue<Pos> bfs;
    for(int w = 1; !pq.empty(); w++)
    {
        
        while(!pq.empty())
        {
            auto top = pq.top();
            if(top.val >= w)break;
            graph[top.p.x][top.p.y] = 0;
            for(auto &d : ways)
            {
                if(graph[top.p.x+d.x][top.p.y+d.y] == -1)
                {
                    graph[top.p.x][top.p.y] = -1;
                    bfs.push(top.p);
                    break;
                }
            }
            pq.pop();
        }
        while(!bfs.empty())
        {
            auto &top = bfs.front();
            for(auto &d : ways)
            {
                if(graph[top.x+d.x][top.y+d.y] < w &&
                graph[top.x+d.x][top.y+d.y] != -1)
                {
                    graph[top.x+d.x][top.y+d.y] = -1;
                    bfs.push({top.x+d.x, top.y+d.y});
                }
            }
            bfs.pop();
        }
        vector<vector<int>> g = graph;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(g[i][j] == 0)
                {
                    g[i][j] = -1;
                    int tmp = dfs(g, i, j, w);
                    ans = max(tmp, ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}