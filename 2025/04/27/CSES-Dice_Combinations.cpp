#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    deque<ssize_t> dp = {1, 1, 2, 4, 8, 16};
    ssize_t sum = 1+1+2+4+8+16;
    size_t n;
    cin >> n;
    while(n--)
    {
        dp.push_back(sum);
        sum -= dp.front();
        if(sum < 0)sum += MOD;
        dp.pop_front();
        sum += dp.back();
        sum %= MOD;
    }
    cout << dp[0];
}
