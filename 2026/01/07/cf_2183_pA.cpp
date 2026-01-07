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
    if(a[0] == 0 && a[n-1] == 0)cout << "Bob\n";
    else cout << "Alice\n";
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

