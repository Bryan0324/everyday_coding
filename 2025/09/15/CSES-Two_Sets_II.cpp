#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const int MOD = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ull n;
    cin >> n;
    if((n*(n+1)/2) & 1)
    {
        cout << "0";
        return 0;
    }
    vector<ull> sum(n*(n+1)/4 + 1);
    sum[0] = 1;
    for(ull i = 1; i < n; i++)
    {
        for(ll s = sum.size()-i-1; s >= 0; s--)
        {
            sum[s+i] += sum[s];
            sum[s+i] %= MOD;
        }
    }
    cout << sum.back();
}