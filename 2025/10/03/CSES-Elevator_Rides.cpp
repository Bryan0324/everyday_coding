#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = unsigned long long;


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for(auto &i : w)cin >> i;
    vector<int> dp(1<<n, n);
    vector<int> last(1<<n, 0);
    dp[0] = 1;
    last[0] = x;
    for (int now = 1; now < 1<<n; now++)
    {
        for(int idx = 0; idx < n; idx++)
        {
            if((now & (1<<idx)) == 0)continue;
            int before = now ^ (1<<idx);
            if(dp[now] < dp[before])continue;
            if(dp[now] == dp[before]
            && last[now] >= last[before]-w[idx])continue;
            dp[now] = dp[before];
            last[now] = last[before]-w[idx];
            if(last[now] < 0)
            {
                last[now] = x - w[idx];
                dp[now]++;
            }
        }
    }
    cout << dp.back();
}
