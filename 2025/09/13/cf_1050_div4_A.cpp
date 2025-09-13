#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
 
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t, n, x;
    cin >> t;
    while(t--)
    {
        cin >> x >> n;
        if((n & 1) == 0)cout << "0\n";
        else cout << x << '\n';
    }
}