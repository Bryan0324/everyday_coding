#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

ssize_t solve()
{
    ssize_t n, k, c;
    cin >> n >> k >> c;
    vector<ssize_t> val(n);
    for(auto &i : val)cin >> i;
    
    vector<ssize_t> dp(n);
    ssize_t ans = max(0ll, val[0]);
    dp[0] = val[0];
    deque<size_t> turn;
    turn.push_back(0);
    for (ssize_t i = 1; i < n; i++)
    {
        dp[i] = max(dp[turn.front()] + val[i]-i*c, val[i]);
        ans = max(ans, dp[i]);
        dp[i] += i*c;
        if(i-turn.front() == k)turn.pop_front();
        while(!turn.empty())
        {
            if(dp[turn.back()] > dp[i])break;
            turn.pop_back();
        }
        turn.push_back(i);
    }
    
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t t;
    cin >> t;
    while(t--)cout << solve() << '\n';

}
