#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    string s;
    cin >> s;
    string ans = s;
    pair<size_t, size_t> p = {0, s.size()-1};
    sort(s.begin(), s.end());
    bool odd = (s.size()&1) == 0;
    for (ssize_t i = 0; i < s.size()-1; i+=2)
    {
        if(s[i] != s[i+1])
        {
            if(!odd)
            {
                odd = true;
                ans[s.size()/2] = s[i];
                i--;
                continue;
            }else 
            {
                cout << "NO SOLUTION";
                return 0;
            }
        }
        ans[p.first] = s[i];
        ans[p.second] = s[i];
        p.first++;
        p.second--;
    }
    if(!odd)ans[s.size()/2] = s.back();
    cout << ans;
}
