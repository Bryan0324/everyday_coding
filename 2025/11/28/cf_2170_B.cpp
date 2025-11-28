#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    ull n, tmp;
    cin >> n;
    ull _n = n;
    vector<ull> v;
    while(_n--)
    {
        cin >> tmp;
        if(tmp != 0)v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ull sum = 0;
    for(auto &i : v)sum += i;
    while(sum < n + v.size() - 1)
    {
        sum -= v.back();
        n -= v.back();
        v.pop_back();
    }
    cout << v.size() << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}
/* 
0 0 0 1 4
*/