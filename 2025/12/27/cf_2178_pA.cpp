#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;



void solve()
{
    string s;
    cin >> s;
    int n = 0;
    for(auto &i : s)if(i == 'Y')n++;
    if(n >= 2)cout << "NO\n";
    else cout << "YES\n";
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

