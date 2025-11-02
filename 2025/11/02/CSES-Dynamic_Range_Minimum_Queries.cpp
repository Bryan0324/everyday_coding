#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
/* 
skw segtree
*/
struct segtree
{
    int n, INIT = 1e9;
    vector<int> node, arr;
    int combine(const int a, const int b)
    {
        return min(a, b);
    }
    segtree(vector<int> &_arr): arr(_arr)
    {
        n = 1<<(__lg(arr.size()-1) + 1);
        node = vector<int>(2*n);
        for(int i = 0; i < arr.size(); i++)
        {
            node[n + i] = arr[i];
        }
        for(int i = n-1; i >= 1; i--)
        {
            node[i] = combine(node[i<<1], node[i<<1|1]);
        }
    }
    int query(int l, int r)
    {
        int res = INIT;
        for(l+=n, r+=n; l < r; l>>=1, r>>=1)
        {
            if(l&1) res = combine(res, node[l++]);
            if(r&1) res = combine(res, node[--r]);
        }
        return res;
    }
    void modify(int p, int x) 
    {
        for(node[p+=n] = x; p > 1; p>>=1)
            node[p>>1] = combine(node[p], node[p^1]);
    }
};


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
    int n, q, op, k, u;
    cin >> n >> q;
    vector<int> x(n);
    for(auto &i : x)cin >> i;
    segtree st(x);
    while(q--)
    {
        cin >> op;
        cin >> k >> u;
        if(op == 1)st.modify(k-1, u);
        else cout << st.query(k-1, u) << '\n';
    }
}

 