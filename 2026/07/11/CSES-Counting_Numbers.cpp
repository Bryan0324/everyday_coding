#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;



ll dp(auto &_dp, string &s, int idx, int prev, bool is_num, bool lim)
{
    if(idx == s.size())return 1;
    if(_dp[idx][prev][is_num][lim] != 0)return _dp[idx][prev][is_num][lim];

    auto &curr = _dp[idx][prev][is_num][lim];

    for(int now = 0; now <= (lim? s[idx]-'0' : 9); now++)
    {
        if(now == prev && (is_num || now != 0))continue;
        curr += dp(_dp, s, idx+1, now,
            (is_num || now != 0),
            (lim && now==s[idx]-'0')
        );
    }
    return curr;
}

ll solve(ll n)
{
    ll _dp[20][11][2][2] = {};
    string s = to_string(n);
    return dp(_dp, s, 0, 10, false, true);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ll a, b;
    
    cin >> a >> b;
    cout << solve(b) - solve(a-1);
}