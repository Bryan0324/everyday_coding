#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;



int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(y == 1)cout << "-1\n";
        else if(x > y && x-y >= 2)cout << "3\n";
        else if(x < y)cout << "2\n";
        else cout << "-1\n";
    }
}