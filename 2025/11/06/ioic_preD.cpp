#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ll INF = LONG_LONG_MAX>>1;

typedef pair<ll, int> path;
#define val first
#define to second
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<path>> graph(n);
    while(m--)
    {
        cin >> a >> b >> w;
        a--; b--;
        graph[b].push_back({w, a});
        graph[a].push_back({w, b});
    }
    vector<ll> dis(n, INF);
    dis[0] = 0;
    priority_queue<path, vector<path>, greater<>> dijk;
    dijk.push({0, 0});
    while(!dijk.empty())
    {
        auto top = dijk.top();
        dijk.pop();
        if(top.val != dis[top.to])continue;
        for(auto &i : graph[top.to])
        {
            if(dis[top.to]+i.val < dis[i.to])
            {
                dis[i.to] = dis[top.to]+i.val;
                dijk.push({dis[i.to], i.to});
            }
        }
    }
    
    int k;
    cin >> k;
    vector<int> idx(k);
    for(auto &i : idx)
    {
        cin >> i;
        i--;
    }
    vector<vector<ll>> v(k, vector<ll>(k));
    for(auto &i : v)for(auto &j : i)cin >> j;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            v[i][j] += dis[idx[i]]+dis[idx[j]];
            if(i == j)
            {
                if(v[i][j] < 0)
                {
                    cout << -1;
                    return 0;
                }
                else v[i][j] = 0;
            }
        }
    }
    for(int mid = 0; mid < k; mid++)
    {
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                v[i][j] = min(v[i][j], v[i][mid]+v[mid][j]);
            }
        }
    }
    for(int mid = 0; mid < k; mid++)
    {
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(v[i][mid]+v[mid][j] < v[i][j])
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    ll ans = -INF;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            ans = max(ans, v[i][j]);
        }
    }
    if(ans >= INF)cout << -1;
    else cout << ans;
}