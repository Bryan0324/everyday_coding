#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, ll> Side;

vector<vector<Side>> graph;

void dfs(int idx, vector<ll> &most)
{
    for(auto &[len, i] : graph[idx])
    {
        if(most[i] == -1)
        {
            most[i] = most[idx]+len;
            dfs(i, most);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    graph.resize(n);

    int u, v;
    ll w;

    for(int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int ret = 0;
    vector<ll> ans(n, 0);
    for(int x = 0; x < 3; x++)
    {
        vector<ll> most(n, -1);
        most[ret] = 0;
        dfs(ret, most);
        for(int i = 0; i < n; i++)
        {
            if(most[ret] < most[i])ret = i;
            ans[i] = max(ans[i], most[i]);
        }
    }
    for(auto &i : ans)cout << i << ' ';
}