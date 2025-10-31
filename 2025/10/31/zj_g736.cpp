#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

ull _c[(int)1e6 + 1][3];
void init_C()
{
    _c[2][0] = _c[1][0] = _c[1][1] = 1;
    _c[2][1] = 2;
    _c[2][2] = 1;
    for(int i = 3; i < (int)1e6 + 1; i++)
    {
        _c[i][0] = 1;
        for(int j = 1; j <= 2; j++)_c[i][j] = _c[i-1][j-1] + _c[i-1][j];
    }
}
ull C(int n, int k)
{
    if(n < k)return 0;
    return _c[n][k];
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    init_C();
    int m, n, k, a, b;
    cin >> m >> n >> k;
    vector<int> r(n, m), c(m, n);
    unordered_map<int, int> s;
    unordered_map<int, int> ds;
    for(int i = -m+1; i < n; i++)
    {
        if(i < 0)s[i] = min(m+i, n);
        else s[i] = min(n-i, m);
    }
    for(int i = 0; i < n+m-1; i++)
    {
        ds[i] = i+1;
        if(i >= m)ds[i] -= i-m+1;
        if(i >= n)ds[i] -= i-n+1;
    }
    while(k--)
    {
        cin >> a >> b;
        r[b]--;
        c[a]--;
        s[b-a]--;
        ds[a+b]--;
    }
    ull ans = 0;
    for(auto &i : r)ans += C(i, 2);
    for(auto &i : c)ans += C(i, 2);
    for(auto &i : s)ans += C(i.second, 2);
    for(auto &i : ds)ans += C(i.second, 2);
    cout << ans*2;
}