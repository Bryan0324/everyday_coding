#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

const int MOD = 1e9+7;


int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t n, x;
    cin >> n >> x;

    vector<pair<size_t, size_t>> a(n);
    vector<size_t> ao(n);
    for(size_t i = 0; i < n; i++)
    {
        cin >> a[i].first;
        ao[i] = a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    sort(ao.begin(), ao.end());
    for(size_t i = 0; i < n; i++)
    {
        if(x < a[i].first)continue;
        auto f = lower_bound(ao.begin(), ao.end(), x-a[i].first) - ao.begin();
        if(f == n || a[i].second == a[f].second || a[f].first != x-a[i].first)continue;
        cout << a[i].second << ' ' << a[f].second;
        return 0;
    }
    cout << "IMPOSSIBLE";
}