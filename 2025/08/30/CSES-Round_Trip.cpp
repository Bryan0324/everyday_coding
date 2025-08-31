#include <bits/stdc++.h>
using namespace std;
 
int dfs(vector<vector<int>> &graph, vector<int> &visited, int p)
{
    int result = -1;
    for(auto &i : graph[p])
    {
        visited[p] = i;
        if(visited[i] != -1)
        {
            if(visited[i] != p)return i;
        }else 
        {
            result = dfs(graph, visited, i);
            if(result != -1)return result;
        }
        // visited[p] = -1;
    }
    return result;
}
 
int main()
{
    int n, m, a, b;
    cin >> n >> m;
 
    vector<vector<int>> graph(n);
    vector<int> visited(n, -1);
    while(m--)
    {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == -1)ans = dfs(graph, visited, i);
        if(ans != -1)break;
    }
    if(ans == -1)cout << "IMPOSSIBLE";
    else 
    {
        vector<int> v = {ans+1};
        for (int i = visited[ans]; i != ans; i = visited[i])
        {
            v.push_back(i+1);
        }
        v.push_back(ans+1);
        cout << v.size() << '\n';
        for(auto &i : v)
        {
            cout << i << ' ';
        }
    }
}
