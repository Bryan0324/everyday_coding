#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> pq_unit;
#define now first
#define add second

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    vector<int> dp(n*2);
    int ans = 0;
    for(int i = 1; i < n*2; i++)
    {
        if(s[i] == '0')dp[i] = dp[i-1]+1;
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        solve();   
    }
}

