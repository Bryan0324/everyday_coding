#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

const ull MOD = 998244353;


void solve()
{
	ull n, tmp;
    unordered_map<ull, ull> m;
	cin >> n;
	for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }
    vector<ull> a;
    for(auto &i : m)a.push_back(i.second);
    sort(a.begin(), a.end());
    vector<ull> dp(n+1);
    dp[0] = 1;
    for(auto &i : a)
    {
        for(int v = n; v >= i; v--)
        {
            dp[v] += dp[v-i]*i %MOD;
            dp[v] %= MOD;
        }
    }
    ull ans = 0;
    for(int i = a.back(); i <= n; i++)
    {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}
/* 
312
213
123 
12 3
21 3
1 23
1 32
13 2
31 2
1 2 3

12
21
1 2

1234 +4
1 234 +3*4
12 34 +2*3 

1 3 10 
*/