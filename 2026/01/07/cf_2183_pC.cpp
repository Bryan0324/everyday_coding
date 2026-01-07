#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int cnt(int l, int r, int m)
{
    int ans = 0;
    for(int discount = 0; discount <= l; discount++)
    {
        if(discount*2 - 1 < m)
        {
            ans = max(ans, 
            discount+min((m - (discount*2 - 1)+discount)/2, r)
            );
        }
    }
    return ans+1;
}

void solve()
{
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    int l = k - 1, r = n - k;
    ans = max(cnt(l, r, m), cnt(r, l, m));
    cout << max(cnt(l, r, m), cnt(r, l, m)) << '\n';
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