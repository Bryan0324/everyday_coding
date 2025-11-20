#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    int cnt[2] = {};
    int last = -1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            cnt[i&1]++;
            last = i&1;
        }
    }
    if((cnt[0] + cnt[1]) & 1)
    {
        if(last == 0)cout << "Ajisai\n";
        else cout << "Mai\n";
    }else cout << "Tie\n";
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}
/* 
7
1 1 1 0 1 0 0
1 0 1 1 0 0 1
*/