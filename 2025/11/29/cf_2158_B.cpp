#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, tmp;
    cin >> n;
    unordered_map<int, int> cnt;
    for(int i = 0; i < n*2; i++)
    {
        cin >> tmp;
        cnt[tmp]++;
    }
    ull ansa = 0, ansb = 0, ansc = 0;
    for(auto &i : cnt)
    {
        if(i.second % 4 == 0)ansa++;
        else if(i.second & 1)ansc++;
        else ansb++;
    }
    if((ansa & 1) && ansc == 0)ansb--;

    cout << ansa*2+ansb*2+ansc << '\n';
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

