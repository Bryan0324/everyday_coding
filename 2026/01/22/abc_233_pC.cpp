#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void dfs(ull n, ull x, ull &ans, vector<vector<ull>> &a)
{
    if(n == a.size())
    {
        if(x == 1)ans++;
        return;
    }
    for(auto &i : a[n])
    {
        if(x % i == 0)dfs(n+1, x/i, ans, a);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n, x, l;
    cin >> n >> x;
    vector<vector<ull>> a(n);
    for(auto &i : a)
    {
        cin >> l;
        i.resize(l);
        for(auto &j : i)cin >> j;
    }
    ull ans = 0;
    dfs(0, x, ans, a);
    cout << ans;
}

