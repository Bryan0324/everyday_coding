#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;
    vector<int> x(n), idx(n+1);
    for(auto &i : x)cin >> i;
    for(int i = 0; i < n; i++)
    {
        idx[x[i]] = i;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(idx[i] < idx[i-1])ans++;
    }
    int a, b;
    while(m--)
    {
        cin >> a >> b;
        a = x[a-1];
        b = x[b-1];
        int before = 0, now = 0;
        if(a != 1)if(idx[a] < idx[a-1])before++;
        if(a != n)if(idx[a+1] < idx[a])before++;
        if(b != 1 && b-1 != a)if(idx[b] < idx[b-1])before++;
        if(b != n && b+1 != a)if(idx[b+1] < idx[b])before++;
        swap(x[idx[a]], x[idx[b]]);
        swap(idx[a], idx[b]);
        if(a != 1)if(idx[a] < idx[a-1])before--;
        if(a != n)if(idx[a+1] < idx[a])before--;
        if(b != 1 && b-1 != a)if(idx[b] < idx[b-1])before--;
        if(b != n && b+1 != a)if(idx[b+1] < idx[b])before--;
        ans -= before;
        cout << ans << '\n';
    }
}
/* 
3 2 1 5 4

1 2 0 4 3

2 1 0 4 3

*/