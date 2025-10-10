#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

bool solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int a = x | z, 
        b = x | y,
        c = y | z;
    //cerr << a << ' ' << b << ' ' << c;
    return 
    (a & b) == x &&
    (b & c) == y &&
    (a & c) == z;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    

    ll t;
    cin >> t;
    while(t--)
    {
        if(solve())cout << "YES\n";
        else cout << "NO\n";
    }
}

/* 
1001
1010
1100

*/