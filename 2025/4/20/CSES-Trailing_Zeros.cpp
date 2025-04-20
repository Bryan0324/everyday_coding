#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1000007;
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, ans = 0;
    cin >> n;
    for (size_t i = 5; i <= n; i+=5)
    {
        size_t now = i;
        while(now % 5 == 0)
        {
            now /= 5;
            ans++;
        }
    }
    cout << ans;
}
