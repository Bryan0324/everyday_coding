#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int closest = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 's')
        {
            closest = 1;
            continue;
        }
        if(i + closest >= s.size())closest = 0;
        if(s[i+closest] == 'u')
        {
            s[i+closest] = 's';
            ans++;
        }
        closest++;
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
/* 
suussssussuuss

*/
