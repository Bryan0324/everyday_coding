#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t

size_t powull(size_t n, size_t m)
{
    if(m == 0)return 1;
    return n*powull(n, m-1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, q;
    cin >> n >> q;
    vector<size_t> v(n);
    for(auto &i : v)cin >> i;
    for (size_t i = 1; i < n; i++)
    {
        v[i] ^= v[i-1];
    }
    size_t a, b;
    while(q--)
    {
        cin >> a >> b;
        a--;b--;
        if(a == 0)cout << v[b] << '\n';
        else cout << (v[b]^v[a-1]) << '\n';
    }
}


/* 

*/
