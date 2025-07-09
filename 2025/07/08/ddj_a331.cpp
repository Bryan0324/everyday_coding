#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, c, v, w, k;
    cin >> n >> c;
    vector<pair<size_t, size_t>> items(n);
    for(auto &i : items)cin >> i.first >> i.second;
    vector<size_t> dp(c+1);
    for(auto &i : items)
    {
        auto &now_v = i.first;
        auto &now_w = i.second;
        for(size_t i = now_w; i <= c; i++)
        {
            dp[i] = max(dp[i-now_w]+now_v, dp[i]);
        }
    }
    cout << dp[c];
}