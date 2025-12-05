#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> pq_unit;
#define now first
#define add second

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    ll min_k = 0, max_k = 0;
    for(int i = 0; i < n; i++)
    {
        ll tmp = min_k;
        min_k = min(min_k-a[i], b[i]-max_k);
        max_k = max(max_k-a[i], b[i]-tmp);
    }
    cout << max_k << '\n';
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

