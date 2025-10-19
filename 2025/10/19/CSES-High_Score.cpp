#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int MOD = 1e9 + 7;

typedef pair<ll, ll> side;

#define val first
#define to second


const ll INF = LLONG_MAX>>1;

void dfs(int idx, vector<vector<int>> &dis_graph, vector<bool> &unvisited)
{
    unvisited[idx] = false;
    for(auto &i : dis_graph[idx])
    {
        if(unvisited[i])dfs(i, dis_graph, unvisited);
    }
    return;
}
int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    ll n, m, a, b, v;
    cin >> n >> m;

    vector<vector<side>> graph(n);
    vector<vector<int>> dis_graph(n);
    while(m--)
    {
        cin >> a >> b >> v;
        a--; b--;
        graph[a].push_back({-v, b});
        dis_graph[b].push_back(a);
    }
    vector<bool> unvisited(n, true);
    unvisited[n-1] = false;
    dfs(n-1, dis_graph, unvisited);
    vector<ll> point(n, INF);
    point[0] = 0;
    queue<int> spfa;
    spfa.push(0);
    vector<int> cnt(n);
    int front = spfa.front();
    for (; cnt[front] <= n && !spfa.empty(); )
    {
        front = spfa.front();
        for(auto &i : graph[front])
        {
            if(unvisited[i.to])continue;
            if(point[i.to] > point[front] + i.val)
            {
                cnt[i.to]++;
                point[i.to] = point[front] + i.val;
                spfa.push(i.to);
            }
        }
        spfa.pop();
    }
    if(!spfa.empty())cout << "-1";
    else cout << -point[n-1];


}