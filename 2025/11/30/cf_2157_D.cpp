#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

ll get(vector<ll> &presum, ll i, ll j, ll p) // [i, j)
{
    return abs((presum[j]-presum[i]) - (j-i)*p);
}

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for(auto &i : a)cin >> i;
    sort(a.begin(), a.end());
    ll l_pos = upper_bound(a.begin(), a.end(), l)-a.begin(),
        r_pos = upper_bound(a.begin(), a.end(), r)-a.begin();
    vector<ll> presum(n+1);
    for(int i = 1; i <= n; i++)
    {
        presum[i] = presum[i-1]+a[i-1];
    }
    ll ans = 0;
    for(ll i = 0; i <= n; i++)
    {
        ans = max(ans, min(
            get(presum, 0, min(i, l_pos), l) - get(presum, min(i, l_pos), max(i, l_pos), l) + get(presum, max(i, l_pos), n, l), // p = l
            get(presum, 0, min(i, r_pos), r) - get(presum, min(i, r_pos), max(i, r_pos), r) + get(presum, max(i, r_pos), n, r)  // p = r
        )); 
        ans = max(ans, min(
            get(presum, 0, min(i, l_pos), l) - get(presum, min(i+1, l_pos), max(i+1, l_pos), l) + get(presum, max(i, l_pos), n, l), // p = l
            get(presum, 0, min(i, r_pos), r) - get(presum, min(i+1, r_pos), max(i+1, r_pos), r) + get(presum, max(i, r_pos), n, r)  // p = r
        )); 
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