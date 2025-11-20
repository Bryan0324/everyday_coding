#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    if(a[0] == -1 && a.back() == -1)a.back() = a[0] = 0;
    if(a[0] == -1 || a.back() == -1)a.back() = a[0] = max(a[0], a.back());
    cout << abs(a[0]-a.back()) << '\n';
    for(auto &i : a)
    {
        if(i == -1)i = 0;
        cout << i << ' ';
    }
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