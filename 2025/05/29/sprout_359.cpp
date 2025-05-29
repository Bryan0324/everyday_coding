#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

const size_t MOD = 1e9+7;
const size_t p = 29;

vector<size_t> ps = {1, p};
unordered_map<size_t, size_t> _p;
size_t ppow(size_t n)
{
    if(_p.find(n) != _p.end())return _p[n];
    size_t &ans = _p[n];
    ans = 1;
    for(size_t i = 1; n != 0; i++)
    {
        if(ps.size() <= i)ps.push_back(ps.back()*ps.back()%MOD);
        if((n & 1) == 1)
        {
            ans *= ps[i];
            ans %= MOD;
        }
        n >>= 1;
    }
    return ans;
}

inline size_t hashget(size_t start, size_t end, vector<size_t> &hashs)
{
    return ( hashs[end] + MOD-(hashs[start]*ppow(end-start)%MOD) )%MOD;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    string s;
    cin >> s;
    vector<size_t> hash_s(t+1);
    for (size_t i = 1; i <= t; i++)
    {
        hash_s[i] = hash_s[i-1]*p%MOD + (s[i-1]-'a'+1);
        hash_s[i] %=MOD;
    }
    size_t fin_ans = 0;
    vector<size_t> ans(t+1, 0);
    size_t cnt = 0;
    for (size_t i = t-1; i > 0; i--)
    {
        for (size_t n = i+1; n <= t && n <= i*2; n++)
        {
            if(ans[n] != 0)continue;
            if(hashget(0, n-i, hash_s) == hashget(i, n, hash_s))
            {
                fin_ans += i;
                ans[n] = i;
                cnt++;
            }else break;
        }
        if(cnt == t)break;
    }
    //for(auto &i : ans)cerr << i << ']';
    cout << fin_ans;
}
/* 
a = s[0:n] (0< n <=t)
a = s[0:i]+s[0:n-i]; (n-i <= i) => n/2 <= i < n => i < n <= 2*i
a = s[0:i]+s[i:n]
*/