#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

bool operator>(string &a, string &b)
{
    char _a, _b;
    for(int i = 0; i < a.size()+b.size(); i++)
    {
        _a = (i < a.size())?a[i]:b[i-a.size()];
        _b = (i < b.size())?b[i]:a[i-b.size()];
        if(_a != _b)return _a > _b;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &i : a)cin >> i;
    string s;
    for(auto &i : a)
    {
        if(s > i)s = i+s;
        else s += i;
    }
    cout << s << '\n';
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

