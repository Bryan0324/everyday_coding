#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n, c;
    cin >> n >> c;
    vector<ull> h(n), d(n-1), presum(n);
    for(auto &i : h)cin >> i;
    for(auto &i : d)cin >> i;
    for (int i = 1; i < n; i++)
    {
        presum[i] = presum[i-1]+d[i-1];
    }
    stack<int> mono;
    ull ans = LLONG_MAX;
    mono.push(n-1);
    for (int i = n-2; i >= 0; i--)
    {
        while(!mono.empty())
        {
            auto top = mono.top();
            if((presum[top]-presum[i]) * min(h[i], h[top]) >= c)
            {
                ans = min(ans, (presum[top]-presum[i]) * min(h[i], h[top]));
            }
            if(h[i] < h[top])break;
            mono.pop();
            if(h[i] == h[top])break;
        }
        mono.push(i);
    }
    if(ans == LLONG_MAX)cout << -1;
    else cout << ans;
}