#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    if(n & 1)
    {
        cout << "0\n";
        return;
    }
    cout << n/4+1 << '\n';
    
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}