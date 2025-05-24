#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, ans = 1;
    cin >> n;
    vector<size_t> dp = {2};
    for (size_t i = 0; n != 0; i++)
    {
        if(dp.size() == i)dp.push_back((dp.back()*dp.back()) %MOD);
        if((n & 1) == 1)
        {
            ans *= dp[i];
            ans %= MOD;
        }
        n /= 2;
    }
    cout << ans;
}
