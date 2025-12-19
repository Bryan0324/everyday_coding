#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    if(!(k & 1))
    {
        k-=2;
        unsigned a = 0, b = 0; 
        int cnt = 0;
        for(int i = 31; i >= 0; i--)
        {
            a<<=1; b<<=1;
            if(n>>i & 1)
            {
                cnt++;
                if(cnt == 1)a++;
                else if(cnt >= 2)b++;
            }else if(cnt >= 2)a++, b++;
        }
        // cerr << (a ^ b) << '\n';
        if(a+b > n && cnt >= 2)cout << a << ' ' << b << ' ';
        else cout << n << " 0 ";
    }
    while(k--)cout << n << ' ';
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
/* 
1000
0111
0111

1101
1110

100100101
100011010
000111111
*/
