#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    for(int i = n; i >= 1; i--)cout << i << ' ';
    cout << n;
    for(int i = 1; i < n; i++)cout << ' ' << i;
    cout << '\n';
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}