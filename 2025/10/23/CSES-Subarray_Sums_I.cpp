#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9 + 7;

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<ull> a(n);
    for(auto &i : a)cin >> i;
    vector<ull> presum(n+1);
    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i-1]+a[i-1];
    }
    ull ans = 0;
    for(int i = 0, j = 0; i <= n; i++)
    {
        while(presum[j]-presum[i] < x)j++;
        if(presum[j]-presum[i] == x)ans++;
    }
    cout << ans;
}