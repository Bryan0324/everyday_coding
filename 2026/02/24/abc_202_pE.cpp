#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

vector<vector<int>> deps;
int DFN = 0;

vector<vector<int>> graph;
vector<pair<int, int>> dfn;

void dfs(int idx, int dep = 0)
{
    while(deps.size() <= dep)deps.push_back({});

    deps[dep].push_back(DFN);
    dfn[idx].first = DFN++;
    for(auto &i : graph[idx])dfs(i, dep+1);
    dfn[idx].second = DFN++;
    
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    graph.resize(n);
    dfn.resize(n);
    for(int i = 1, p; i < n; i++)
    {
        cin >> p;
        p--;
        graph[p].push_back(i);
    }
    dfs(0);
    int q, u, d;
    cin >> q;
    while(q--)
    {
        cin >> u >> d;
        u--;
        if(d >= deps.size())cout << "0\n";
        else cout << upper_bound(deps[d].begin(), deps[d].end(), dfn[u].second) - 
            lower_bound(deps[d].begin(), deps[d].end(), dfn[u].first) << '\n';
    }
}