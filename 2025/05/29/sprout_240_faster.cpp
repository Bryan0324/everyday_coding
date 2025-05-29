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
size_t _p[(int)1e5*5+5] = {};
inline size_t ppow(size_t n)
{
    if(_p[n] != 0)return _p[n];
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

int main()
{
    //cin.tie(0)->sync_with_stdio(false);
    size_t n = 0;
    size_t hash_str[(int)1e5*5+5] = {};
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ++n;
        hash_str[n] = hash_str[n-1]*p + (c-'a');
        hash_str[n] %=MOD;
    }
    size_t ans = 1;
    for (; ans <= n; ans++)
    {
        if(hash_str[ans] != (hash_str[n]+MOD-(hash_str[n-ans]*ppow(ans)%MOD))%MOD)continue;
        size_t far = ans;

        for (size_t i = (ans+1)/2; i <= n-ans; i++)
        {
            if(hash_str[ans] == (hash_str[ans+i]+MOD-(hash_str[i]*ppow(ans)%MOD))%MOD)
            {
                far = ans+i;
                i += (ans+1)/2-1;
            }else if(i >= far)break;
        }
        if(far == n)
        {
            cout << ans;
            return 0;
        }
        ans += ans/2;
    }
}