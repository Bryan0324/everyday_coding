#include<bits/stdc++.h>
using namespace std;

const size_t MOD = 1000000007;
#define unsigned long long size_t
struct pos : pair<size_t, size_t>
{
    size_t &a = this->first;
    size_t &b = this->second;
    pos operator= (pair<size_t, size_t> a)
    {
        this->first = a.first;
        this->second = a.second;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    pos range;
    if(a > b)
    {
        n = n-b+1;
        a = a-b+1;
        b = 1;
    }else
    {
        n = b;
        a = b-(a-1);
        b = 1;
    }
    //cerr << b << ' ' << a << ' ' << n << '\n';
    vector<vector<ssize_t>> dp(k+1, vector<ssize_t>(n+2, 0ull));
    dp[0][a] = 1;
    dp[0][a+1] = -1;
    for(int i = 0; i < k; i++)
    {
        ssize_t now = 0;
        for(int j = 2; j <= n; j++)
        {
            now += dp[i][j];
            now %= MOD;
            if(now != 0)
            {
                dp[i+1][2] += now;
                dp[i+1][2] %= MOD;
                dp[i+1][j] += MOD-now;
                dp[i+1][j] %= MOD;
                dp[i+1][j+1] += now;
                dp[i+1][j+1] %= MOD;
                dp[i+1][min(j+j-2, n)+1] += MOD-now;
                dp[i+1][min(j+j-2, n)+1] %= MOD;
            }
            //cerr << "    " << '[' << now << ']';
            //for(auto &j : dp[i+1])cerr << j << ' ';
            //cerr << '\n';
        }
        //for(auto &j : dp[i+1])cerr << j << ' ';
        //cerr << '\n';
    }
    ssize_t ans = 0, now = 0;
    for(size_t i = 2; i <= n; i++)
    {
        now += dp[k][i];
        now %= MOD;
        //cerr << now << ']';
        ans += now;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
/*

*/
