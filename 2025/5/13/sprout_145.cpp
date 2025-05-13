#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

string solve()
{
    size_t n, m, c, k;
    cin >> n >> m;
    vector<size_t> dp(m+1);
    dp[0] = 1;
    vector<size_t> state(m+3000);
    while(n--)
    {
        cin >> c >> k;
        for (size_t i = 0; i <= m; i++)
        {
            if(dp[i] != 0)state[i+c] = k;
            if(state[i] != 0)
            {
                state[i+c] = max(state[i+c], state[i]-1);
                state[i] = 0;
                dp[i] = 1;
            }
        }
    }
    return dp[m] == 1 ? "Yes" : "No";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t t;
    cin >> t;
    while(t--)cout << solve() << '\n';

}
