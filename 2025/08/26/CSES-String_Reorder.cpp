#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("O3")

using ull = unsigned long long;


int solve()
{
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {};
    for(auto &i : s)cnt[i-'A']++;
    vector<int> ans(n+1, 27);
    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if((n-i+1)/2 < cnt[c])
            {
                if(ans[i-1] == c)return -1;
                if(ans[i] != 27)cnt[ans[i]]++;
                cnt[c]--;
                ans[i] = c;
                break;
            }
            if(cnt[c] != 0 && ans[i-1] != c && ans[i] == 27)
            {
                cnt[c]--;
                ans[i] = c;
            }
        }
        if(ans[i] == 27)return -1;
    }
    for (int i = 1; i <= n; i++)cout << (char)('A'+ans[i]);
    return 0;
}

int main()
{
    if(solve() == -1)cout << "-1";
}