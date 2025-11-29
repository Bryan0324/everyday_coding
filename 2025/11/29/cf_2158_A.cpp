#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int y, r;
    cin >> y >> r;
    cout << min(n, y/2+r) << '\n';
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