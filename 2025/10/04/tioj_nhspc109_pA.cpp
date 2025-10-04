#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ll, ll> stone; 
#define w second
#define p first
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    
    vector<stone> wp(n);
    for(auto &i : wp)cin >> i.w >> i.p;
    sort(wp.begin(), wp.end(), greater<>());
    ll ans = 0, ptr = 0;
    while(m > 0 && ptr != n)
    {
        ans += wp[ptr].p*min(m, wp[ptr].w);
        m -= wp[ptr++].w;
    }
    cout << ans;
}
