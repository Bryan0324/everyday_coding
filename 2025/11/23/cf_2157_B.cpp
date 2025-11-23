#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n;
    int ta, tb;
    cin >> n;
    cin >> ta >> tb;
    string ops;
    cin >> ops;
    int xoy = 0, xny = 0;
    for(auto &i : ops)
    {
        if(i == '4')xoy++;
        else xny++;
    }
    ta = abs(ta); tb = abs(tb);
    ta -= xny;
    tb -= xny;
    if(ta < 0)ta = 0;
    if(tb < 0)tb = 0;
    if(ta + tb <= xoy)cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}