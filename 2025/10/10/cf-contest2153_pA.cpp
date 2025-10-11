#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

void solve()
{
    ll n, tmp;
    cin >> n;
    unordered_set<int> s;
    while(n--)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    

    ll t;
    cin >> t;
    while(t--)solve();
}