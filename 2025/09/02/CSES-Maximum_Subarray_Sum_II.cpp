#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ull n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    vector<ll> presum(n+1);
    for (ull i = 1; i <= n; i++)
    {
        presum[i] = presum[i-1] + v[i-1];
    }
    ll ans = presum[a];
    multiset<ll> s;
    s.insert(presum[0]);
    int fptr = 0, bptr = 0;
    for(ull i = a; i <= n; i++)
    {
        ans = max(ans, presum[i] - *s.begin());
        if(i - fptr == b)s.erase(s.find(presum[fptr++]));
        s.insert(presum[++bptr]);
    }
    cout << ans;
}