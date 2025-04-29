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
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n, m, a, b;
    cin >> n >> m;
    djs d(n);
    while(m--)
    {
        cin >> a >> b;
        a--; b--;
        d.join(a, b);
    }
    vector<pair<size_t, size_t>> ans;
    for (size_t i = 1; i < n; i++)
    {
        if(d.f(0) != d.f(i))
        {
            ans.push_back( {1, i+1} );
            d.join(0, i);
        }
    }
    cout << ans.size() << '\n';
    for(auto &i : ans)cout << i.first << ' ' << i.second << '\n';
}
