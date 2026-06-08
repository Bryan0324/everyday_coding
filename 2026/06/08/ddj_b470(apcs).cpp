#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

void solve(vector<ull> &sum)
{
    ull l, r, a, b;
    cin >> l >> r >> a >> b;
    l--;
    ull s = sum[r]-sum[l], lb = sum[l];
    while(l+1 < r)
    {
        ull mid = (l+r)/2;
        if(a*s <= (sum[mid]-lb)*(a+b))r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ull n, m;
    cin >> n >> m;
    vector<ull> w(n);
    ull s = 0;
    for(auto &i : w)
    {
        cin >> i;
        s += i;
    }
    vector<ull> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + w[i-1];
    }
    while(m--)solve(sum);
}