#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n;
    cin >> n;
    ull ans = 0;
    for(ull cnt = 2; n >= cnt/2; cnt<<=1)
    {
        ans += ((n+1)/cnt)*(cnt/2);
        if((n+1)%cnt > cnt/2)ans += (n+1)%cnt - cnt/2;
    }
    cout << ans;
}