#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, tmp, m = -1, ans = 0;
    cin >> n;
    while(n--)
    {
        cin >> tmp;
        if(m > tmp)ans++;
        else m = tmp;
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

