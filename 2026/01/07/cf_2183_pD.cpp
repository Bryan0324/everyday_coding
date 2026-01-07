#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

void dfs(vector<vector<int>> &graph, list<deque<int>>::iterator deeps, vector<int> &fa, int idx = 0)
{
    deeps->push_back(idx);
    for(auto &i : graph[idx])
    {
        if(fa[i] == -1)
        {
            fa[i] = idx;
            dfs(graph, next(deeps), fa, i);
        }
    }
}
void solve()
{
    int n, u, v, ans = 0;
    cin >> n;
    vector<vector<int>> graph(n);
    list<deque<int>> deeps(n);
    vector<int> fa(n, -1);
    fa[0] = 0;
    while(--n)
    {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v); 
        graph[v].push_back(u);
    }
    dfs(graph, deeps.begin(), fa);
    int deep = 0;
    while(deeps.back().size() == 0)deeps.pop_back();
    for(auto &i : deeps)
    {
        int d = fa[i[0]];
        int add = 1;
        for(auto &j : i)
        {
            if(d != fa[j])
            {
                add = 0;
                break;
            }
        }
        if(ans < (int)i.size()+add)
        {
            ans = (int)i.size()+add;
        }
    }
    cout << ans << '\n';
    reverse(deeps.begin(), deeps.end());
    while(deeps.size() != 0)
    {
        int before = -1;
        vector<int> pre;
        for(auto it = deeps.begin(); it != deeps.end(); )
        {
            if(it->front() != before)
            {
                before = fa[it->front()];
                pre.push_back(it->front());
                it->pop_front();
            }else if(it->back() != before)
            {
                before = fa[it->back()];
                pre.push_back(it->back());
                it->pop_back();
            }
            it++;
            if(next(it, -1)->size() == 0)deeps.erase(next(it, -1));
        }
        cout << pre.size() << ' ';
        for(auto &i : pre)cout << i+1 << ' ';
        cout << '\n';
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}
/* 

1 2 3 4

*/