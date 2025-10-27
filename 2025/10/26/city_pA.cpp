#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9 + 7;

ull _level[(int)1e6+5] = {};

void init_level(int a)
{
    _level[1] = 1;
    for(int i = 2; i < a; i++)
    {
        _level[i] = _level[i-1]*i %MOD;
    }
}


unordered_map<ull, ull> _div;
ull div(ull b)
{
    if(_div[b] != 0)return _div[b];
    _div[b] = 1;
    ull d = MOD - 2;
    ull mulit = b;
    while(d != 0)
    {
        if(d & 1)_div[b] *= mulit;
        mulit *= mulit;

        _div[b] %= MOD;
        mulit %= MOD;
        d >>= 1;
    }
    return _div[b];
}

ull C(ull a, ull b)
{
    if(a == b)return 1;
    if(a < b || b < 0 || a < 0)return 0;
    return (_level[a]*div(_level[b])%MOD *div(_level[a-b]))%MOD;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a >> b >> c;
    if(c == 1)
    {
        if(a >= c)cout << b+1;
        else cout << 0;
        return 0;
    }
    ll ans = 0;

    init_level(max(a, b+2));/* 
    if(a >= c)for(int i = b; i >= c-1; i--)
    {
        ans += ((C(a-1, c-1) * C(i-1, c-2))%MOD) * (b-i+1) % MOD;
        ans %= MOD;
    } */
    cout << (C(a-1, c-1) * C(b+1, c)) %MOD;
}
/* 
C(c-2, c-2) + C(c-1, c-2) ... 
4!/1!/3!
i-1
*/
