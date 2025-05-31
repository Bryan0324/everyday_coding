#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

const int MOD = 1000000007;


int dp[(int)1e4*3/2+2];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    vector<size_t> r(1e4*3/2+2);
    r[0] = 1;
    for(size_t i = 1; i <= (int)1e4*3/2; i++)
    {
        for(size_t j = 0; i > j; j++)
        {
            r[j+1] += r[j];
            r[j+1] %= MOD;
        }
        dp[i] = r[i];
    }
    size_t t;
    while(cin >> t)
    {
        if((t & 1) == 1)cout << "Error404\n";
        else cout << dp[t/2] << '\n';
    }
}