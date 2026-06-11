#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    int ptr = 0;
    vector<set<int>> pos(n);
    unordered_map<int, int> cnt(n);
    for(int l, r, pl = 0, pr = 0; q--; pl = l, pr = r)
    {
        cin >> l >> r;
        l--;
        if(pl == pr)pl = pr = l;
        for(; pl < l && pl < pr; pl++)
        {
            pos[cnt[a[pl]]].erase(pos[cnt[a[pl]]].find(a[pl]));
            pos[--cnt[a[pl]]].insert(a[pl]);
            if(pos[ptr].size() == 0)ptr--;
        }

        if(pl == pr)pl = pr = l;
        for(; pr < r; pr++)
        {
            
            if(cnt[a[pr]] == ptr)ptr++;
            if(cnt[a[pr]] != 0)pos[cnt[a[pr]]].erase(pos[cnt[a[pr]]].find(a[pr]));
            pos[++cnt[a[pr]]].insert(a[pr]);
        }

        cout << *next(pos[ptr].end(), -1) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull t;
    cin >> t;
    while(t--)solve();
}