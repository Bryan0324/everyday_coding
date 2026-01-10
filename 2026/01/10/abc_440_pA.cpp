#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int x, y;
    cin >> x >> y;
    while(y--)x *= 2;
    cout << x;
}