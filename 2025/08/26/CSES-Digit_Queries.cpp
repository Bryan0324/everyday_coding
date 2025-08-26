#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")

using ull = unsigned long long;

char solve()
{
    ull n;
    cin >> n;
    ull t = 1, d = 9, bef = 0;
    for(; n > d*t; d *= 10, t++)
    {
        bef += d;
        n -= d*t;
    }
    return to_string(bef+(n+t-1)/t)[(n-1)%t];
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--)cout << solve() << '\n';
}
/* 
9

9 + 89*2

899*3

*/