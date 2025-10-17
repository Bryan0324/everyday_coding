#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001] = {};
const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k, a;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while(k--)
        {
            cin >> a;
            a--;
            for(int j = 0; j < i; j++)
            {
                dp[i][j] += dp[a][j];
                dp[i][j] %= MOD;
            }
        }
        dp[i][i]++;
        for(int j = 0; j <= i; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    
}