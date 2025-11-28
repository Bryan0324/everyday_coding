#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    ull n, k;
    cin >> n >> k;
    vector<ull> q(n);
    for(auto &i : q)cin >> i;
    sort(q.begin(), q.end());
    vector<ull> r(n);
    for(auto &i : r)cin >> i;
    sort(r.begin(), r.end());
    ull ans = 0;
    for(int i = n-1, j = 0; i >= 0 && j < n; )
    {
        if(q[i]*(r[j]+1) + r[j] <= k)
        {
            i--; j++;
            ans++;
        }else i--;
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


/* 
q*y + r = x && 0 <= r < y
k-r = q*y
k-q*y = r

y == 1
q + r == x
*/