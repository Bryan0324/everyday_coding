#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9+7;


void solve()
{
    ull a, b;
    cin >> a >> b;
    ull ans = 1;
    while(b != 0)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b>>=1;
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        solve();   
    }
}

