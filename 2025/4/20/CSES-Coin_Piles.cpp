#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    size_t n, m;
    while(t--)
    {
        cin >> n >> m;
        if(n > m)swap(n, m);
        if((n+m) % 3 != 0 || ((n != 0) != (m != 0)) || m-n > n)cout << "NO\n";
        else cout << "YES\n";
    }
}
 
/* 
11 4
 
*/
