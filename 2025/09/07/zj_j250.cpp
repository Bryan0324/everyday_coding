#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

ull _c[51][51] = {};

ull C(int n, int k)
{
    if(n < k)return 0;
    if(n-k < k)k = n-k;
    if(n == 0 || k == 0)return 1;
    if(_c[n][k] == 0)_c[n][k] = C(n-1, k) + C(n-1, k-1);
    return _c[n][k];
}

int seek(int k, int begin, int end, ull target)
{
    if(begin+1 == end)return end;

    auto mid = (begin+end)/2;

    if(target <= C(mid, k))end = mid;
    else begin = mid;

    //cerr << mid << ' ' << C(mid, k) << ' ' << target << "\n";

    return seek(k, begin, end, target);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k;
    ull m;
    cin >> n >> k >> m;
    string ans(n, '0');

    for (; k != 0; k--)
    {
        n = seek(k, k-1, n, m)-1;
        m -= C(n, k);
        ans[n] = '1';
        //cerr << n+1 << "\n\n";
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}