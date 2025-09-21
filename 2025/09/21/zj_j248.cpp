#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;

struct Side
{
    int to;
    ull c, l;
    Side(int _to = 0, ull _c = 0, ull _l = 0):to(_to), c(_c), l(_l) {};

    ll profit(int cnt)
    {
        return l - c*cnt;
    }
    ll twice()
    {
        return l - c*2;
    }
};

int n, m;
vector<ull> h;
int dfs(int idx, ll &earn, vector<vector<Side>> &graph, vector<bool> &visited)
{
    int cnt = h[idx];
    for(auto &i : graph[idx])
    {
        if(visited[i.to])continue;
        visited[i.to] = true;
        int need = dfs(i.to, earn, graph, visited);
        if(need == 0)
        {
            if(i.twice() > 0)earn += i.twice();
        }else
        {
            earn += i.profit(abs(need));
            cnt -= need;
        }
    }
    return m - cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    cin >> n >> m;
    h = vector<ull>(n);
    for(auto &i : h)cin >> i;
    int idx1, idx2, c, l;
    vector<vector<Side>> graph(n);
    vector<bool> visited(n);
    while(--n)
    {
        cin >> idx1 >> idx2 >> c >> l;
        idx1--; idx2--;
        if(l <= 150)l *= 2;
        else l = 300 + (l-150);
        graph[idx1].push_back(Side(idx2, c, l));
        graph[idx2].push_back(Side(idx1, c, l));
    }
    visited[0] = true;
    ll earn = 0;
    dfs(0, earn, graph, visited);
    cout << earn;
}