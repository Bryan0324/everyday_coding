#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main()
{
    string _s;
    cin >> _s;
    vector<string> s = {_s, _s};
    int t;
    cin >> t;
    int l, r, k, n;
    for(int idx = 0; idx < t; idx++)
    {
        cin >> l >> r >> k;
        l--; r--;
        n = r-l+1;
        for(int i = 0; i < n; i++)
        {
            s[(idx+1)&1][l+(i+k)%n] = s[idx&1][l + i];
        }
        s[idx&1] = s[(idx+1)&1];
    }
    cout << s[t&1];
}
