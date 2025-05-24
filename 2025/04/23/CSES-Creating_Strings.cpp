#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
unordered_map<char, size_t> um;

void dfs(size_t cnt, vector<string> &ans, string now = "")
{
    if(cnt == 0)
    {
        ans.push_back(now);
        return;
    }
    for (auto &i : um)
    {
        if(i.second != 0)
        {
            i.second--;
            dfs(cnt-1, ans, now+i.first);
            i.second++;
        }
    }
    return;
    
}

int main()
{
	string s;
    //cin.tie(0)->sync_with_stdio(false);

    cin >> s;
    sort(s.begin(), s.end(), greater<>());
    for (auto &c : s)um[c]++;
    vector<string> ans;
    dfs(s.size(), ans);
    cout << ans.size() << '\n';
    for(auto &i : ans) cout << i << '\n';
}
/* 

*/
