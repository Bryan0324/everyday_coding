#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;



void solve()
{
    int l, a, b;
    cin >> l >> a >> b;
    int ans = 0;
    for(int i = 1; i <= l; i++)
    {
        ans = max(ans, (a+b*i)%l);
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

