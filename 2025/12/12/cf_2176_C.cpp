#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    ull n, tmp;
    cin >> n;
    vector<ull> even, odd;
    while(n--)
    {
        cin >> tmp;
        if(tmp & 1)odd.push_back(tmp);
        else even.push_back(tmp);
    }
    n = odd.size()+even.size();
    sort(even.begin(), even.end(), greater<>());
    sort(odd.begin(), odd.end());
    vector<ull> presum(even.size()+1);
    for(ull i = 1; i <= even.size(); i++)
    {
        presum[i] = presum[i-1] + even[i-1];
    }
    ull left = 1, e = 0;
    for(ull k = 1; k <= n; k++)
    {
        if(odd.size() == 0)
        {
            cout << "0 ";
            continue;
        }
        if(left > odd.size() || !(left & 1))cout << "0 ";
        else cout << presum[e]+odd.back() << ' ';
        if(e < even.size())e++;
        else if(e == 0)left++;
        else
        {
            e--;
            left+=2;
        }
    }
    cout << '\n';
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