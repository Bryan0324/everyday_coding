#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ull, int> path;
#define val first
#define to second

const ull INF = LLONG_MAX;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<vector<path>> graph(n);

    int a, b, c;
    while(m--)
    {
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c, b});
    }

    vector<ull> used(n, INF), unused(n, INF);
    priority_queue<pair<path, bool>, vector<pair<path, bool>>, greater<>> pq;
    pq.push({{0, 0}, false});
    while(!pq.empty())
    {
        auto [top, use] = pq.top();
        pq.pop();
        vector<ull> *now;
        if(use)now = &used;
        else now = &unused;
        if((*now)[top.to] <= top.val)continue;
        (*now)[top.to] = top.val;
        for(auto &i : graph[top.to])
        {
            if((*now)[i.to] == INF)
            {
                pq.push({{i.val+(*now)[top.to], i.to}, use});
                if(!use) pq.push({{i.val/2+(*now)[top.to], i.to}, true});
            }
        }
    }
    cout << min(unused[n-1], used[n-1]);
}
