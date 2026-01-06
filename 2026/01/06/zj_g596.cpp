#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void add(int r, int c, vector<vector<int>> &graph, int &cnt, int diff)
{
    int d = 1;
    if(diff > 0)
    {
        if(graph[r][c] == 0)cnt++;
        graph[r][c] = -1;
    }
    if(diff < 0)
    {
        if(graph[r][c] != 0)cnt--;
        graph[r][c] = 0;
    }

    for(int d = r+1; d < graph.size(); d++)
    {
        if(graph[d][c] == -1)
        {
            for(--d; d > r; d--)
            {
                if(diff < 0 && graph[d][c] == 0)break;
                if(diff > 0)if(graph[d][c] == 0)cnt++;
                graph[d][c]+=diff;
                if(diff < 0)if(graph[d][c] == 0)cnt--;
            }
            break;
        }
    }
    for(int d = r-1; d >= 0; d--)
    {
        if(graph[d][c] == -1)
        {
            for(++d; d < r; d++)
            {
                if(diff < 0 && graph[d][c] == 0)break;
                if(diff > 0)if(graph[d][c] == 0)cnt++;
                graph[d][c]+=diff;
                if(diff < 0)if(graph[d][c] == 0)cnt--;
            }
            break;
        }
    }
    for(int d = c+1; d < graph[r].size(); d++)
    {
        if(graph[r][d] == -1)
        {
            for(--d; d > c; d--)
            {
                if(diff < 0 && graph[r][d] == 0)break;
                if(diff > 0)if(graph[r][d] == 0)cnt++;
                graph[r][d]+=diff;
                if(diff < 0)if(graph[r][d] == 0)cnt--;
            }
            break;
        }
    }
    for(int d = c-1; d >= 0; d--)
    {
        if(graph[r][d] == -1)
        {
            for(++d; d < c; d++)
            {
                if(diff < 0 && graph[r][d] == 0)break;
                if(diff > 0)if(graph[r][d] == 0)cnt++;
                graph[r][d]+=diff;
                if(diff < 0)if(graph[r][d] == 0)cnt--;
            }
            break;
        }
    }
}


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, h;
    cin >> n >> m >> h;
    int r, c, t, ans = 0, cnt = 0;
    vector<vector<int>> graph(n, vector<int>(m));
    while(h--)
    {
        cin >> r >> c >> t;
        // r--; c--;
        if(t == 1 || graph[r][c] == 1)add(r, c, graph, cnt, -1);
        if(t == 0)add(r, c, graph, cnt, 1);

        ans = max(cnt, ans);
/*         for(auto &i : graph)
        {
            for(auto &j : i)cerr << (char)(j+'0') << ' ';
            cerr << '\n';
        }
        cerr << '\n'; */
    }
    cout << ans << '\n';
    cout << cnt;
}
