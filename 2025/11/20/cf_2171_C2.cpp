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
    bitset<20> cnt;
    int last[20] = {};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(((a[i]>>j)&1) != ((b[i]>>j)&1))
            {
                cnt[j].flip();
                last[j] = i&1;
            }
        }
    }
    int domain = -1;
    for(int i = 20-1; i >= 0; i--)
    {
        if(cnt[i])
        {
            domain = last[i];
            break;
        }
    }
    if(domain == -1)cout << "Tie\n";
    else if(domain & 1)cout << "Mai\n";
    else cout << "Ajisai\n";
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