#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ull, pair<ull, ull>> Node;
#define val first
#define to second.first
#define no second.second

const ull MOD = 998244353;

void solve()
{
    ull NOTE = 0;
    ll n, m;
    cin >> n >> m;
    vector<ull> a(n);
    for(auto &i : a)cin >> i;
    ull tmpa, tmpb;
    vector<vector<Node>> graph(n);
    while(m--)
    {
        cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        graph[tmpa].push_back({a[tmpb], {tmpb, NOTE++}});
    }
    for(auto &i : graph)sort(i.begin(), i.end());
    vector<vector<ull>> new_graph(NOTE);
    vector<ull> in(NOTE);
    for(int i = 0; i < n; i++)
    {
        for(auto &j : graph[i])
        {
            auto kend = lower_bound(graph[j.to].begin(), graph[j.to].end(), (Node){a[i]+j.val, {LLONG_MAX, LLONG_MAX}});
            auto kstart = lower_bound(graph[j.to].begin(), graph[j.to].end(), (Node){a[i]+j.val, {0, 0}});
            for(auto k = kstart; k != kend; k++)
            {
                new_graph[j.no].push_back(k->no);
                in[k->no]++;
            }
        }
    }
    vector<ull> dp(NOTE, 1);
    queue<ull> topical;
    for(int i = 0; i < NOTE; i++)if(in[i] == 0)topical.push(i);
    while(!topical.empty())
    {
        auto &top = topical.front();
        for(auto &i : new_graph[top])
        {
            in[i]--;
            if(in[i] == 0)topical.push(i);
            dp[i] += dp[top];
            dp[i] %= MOD;
        }
        topical.pop();
    }
    ull ans = 0;
    for(auto &i : dp)
    {
        ans += i;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}