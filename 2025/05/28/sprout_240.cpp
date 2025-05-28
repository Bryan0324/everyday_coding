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
const size_t p = 26;
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

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    size_t n = s.size();
    vector<size_t> hash_str(n+1);
    for(size_t i = 1; i <= n; i++)
    {
        hash_str[i] = hash_str[i-1]*p%MOD + (s[i-1]-'a'+2);
        hash_str[i] %=MOD;
    }
    vector<size_t> dp(n+1);
    unordered_map<size_t, size_t> dp_to_kcnt;
    queue<size_t> ks;
    ks.push(1);
    dp_to_kcnt[1] = 1;
    dp[0] = 0; dp[1] = 1;
    for(size_t i = 2; i <= n; i++)
    {
        dp[i] = i;
        if(!ks.empty())if(ks.front()+dp[ks.front()] < i)
        {
            dp_to_kcnt[dp[ks.front()]]--;
            if(dp_to_kcnt[dp[ks.front()]] == 0)dp_to_kcnt.erase(dp[ks.front()]);
            ks.pop();
        }
        //cerr << "now:" << hash_str[i] << '\n';
        if(!dp_to_kcnt.empty())for(auto &k : dp_to_kcnt)
        {
            //cerr << "   pair:" << hash_str[k.first] << ' ' << hash_str[i-k.first]*ppow(k.first) << '\n';
            if(hash_str[k.first] == (hash_str[i]+MOD-(hash_str[i-k.first]*ppow(k.first)%MOD))%MOD
                )dp[i] = min(dp[i], k.first);
            //cerr << '[' << dp[i] << ']';
        }
        //cerr << "result:" << hash_str[dp[i]] << ' ' << (hash_str[n]+MOD-(hash_str[n-dp[i]]*ppow(dp[i])%MOD))%MOD << '\n';
        if(hash_str[dp[i]] == (hash_str[n]+MOD-(hash_str[n-dp[i]]*ppow(dp[i])%MOD))%MOD)
        {
        	dp_to_kcnt[dp[i]]++;
        	ks.push(i);
		}
    }
    cout << dp[n];
}