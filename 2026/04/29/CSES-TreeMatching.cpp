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
    vector<int> size(n);
    for(int u, v, i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--; v--;
        size[u]++;
        graph[u].push_back(v);
        size[v]++;
        graph[v].push_back(u);
    }
    queue<int> topi;
    vector<int> visited(n);
    for(int i = 0; i < n; i++)
    {
        if(size[i] == 1)topi.push(i);
    }
    int ans = 0;
    while(!topi.empty())
    {
        auto top = topi.front();
        topi.pop();
        visited[top] = true;
        for(auto &i : graph[top])
        {
            if(visited[i])continue;
            visited[i] = true;
            for(auto &j : graph[i])
            {
                if(!visited[j])if(--size[j] == 1)topi.push(j);
            }
            ans++;
            break;
        }
        for(auto &i : graph[top])
        {
            if(visited[i])continue;
            if(--size[i] == 1)topi.push(i);
        }
    }
    cout << ans;
}