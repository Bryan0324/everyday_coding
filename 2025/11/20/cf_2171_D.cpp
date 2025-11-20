#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

struct DSU
{
    vector<int> boss;
    DSU(int _n)
    {
        boss.resize(_n);
        for (int i = 0; i < _n; i++)
        {
            boss[i] = i;
        }
    }
    int query(int q)
    {
        if(boss[q] != q)boss[q] = query(boss[q]);
        return boss[q];
    }
    void merge(int a, int b)
    {
        a = query(a); b = query(b);
        if(a > b)swap(a, b);
        boss[b] = a;
    }
};

void solve()
{
    int n, tmp;
    cin >> n;
    vector<int> p(n);
    for(auto &i : p)
    {
        cin >> i;
        i--;
    }
    DSU djs(n);
    stack<int> mono;
    for(auto &i : p)
    {
        while(!mono.empty())
        {
            if(mono.top() >= i)break;
            djs.merge(mono.top(), i);
            mono.pop();
        }
        mono.push(djs.query(i));
    }
    if(mono.size() == 1)cout << "Yes\n";
    else cout << "No\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}
/* 
7
1 1 1 0 1 0 0
1 0 1 1 0 0 1
*/