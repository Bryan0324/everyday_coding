#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
struct djs
{
    vector<size_t> to;
    vector<size_t> s;
    djs(size_t n)
    {
        to = vector<size_t>(n);
        for(size_t i = 0; i < n; i++)to[i] = i;
        s = vector<size_t>(n, 1);
    }
    size_t f(const size_t &n)
    {
        if(to[n] != n)to[n] = f(to[n]);
        return to[n];
    }
    void join(const size_t &n, const size_t &m)
    {
        if(f(n) == f(m))return;
        else raw_join(f(n), f(m));
        return;
    }
    void raw_join(size_t n, size_t m)
    {
        if(s[n] < s[m])swap(n, m);
        to[m] = n;
        s[n] += s[m];
        return;
    }
};
 
 
int main()
{
    //cin.tie(0)->sync_with_stdio(false);
    
    size_t n, m, a, b;
    cin >> n >> m;
    djs d(n);
    unordered_map<size_t, unordered_map<size_t, size_t>> canva;
    while(m--)
    {
        cin >> a >> b;
        a--; b--;
        d.join(a, b);
        canva[a][b] = 1;
        canva[b][a] = 1;
    }
    if(d.f(0) != d.f(n-1))
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<size_t> visited(n);
    for(size_t i = 0; i < n; i++)visited[i] = i;
 
    queue<size_t> bfs;
    bfs.push(0);
    while(!bfs.empty())
    {
        auto &now = bfs.front();
        if(now == n-1)break;
        for(auto &i : canva[now])
        {
            if(visited[i.first] == i.first)
            {
                visited[i.first] = now;
                bfs.push(i.first);
            }
        }
        bfs.pop();
    }
    stack<size_t> ans;
    size_t now = n-1;
    ans.push(n-1);
    while(now != 0)
    {
        now = visited[now];
        ans.push(now);
    }
    cout << ans.size() << '\n';
    while(!ans.empty())
    {
        cout << ans.top()+1 << ' ';
        ans.pop();
    }
    return 0;
}
