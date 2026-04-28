#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;



int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int u, v, i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto bfs = [&](int idx) -> pair<int, int>
    {
        queue<pair<int, int>> bfs;
        bfs.push({idx, 0});
        vector<bool> visited(n);
        visited[idx] = true;
        while(!bfs.empty())
        {
            auto &[top, size] = bfs.front();
            for(auto &i : graph[top])
            {
                if(visited[i])continue;
                visited[i] = true;
                bfs.push({i, size+1});
            }
            if(bfs.size() == 1)break;
            bfs.pop();
        }
        return bfs.front();
    };
    auto [top, s] = bfs(0);
    auto [a, size] = bfs(top);
    cout << size;
}