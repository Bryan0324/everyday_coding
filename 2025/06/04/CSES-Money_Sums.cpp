#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long



int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n;
    cin >> n;
    vector<size_t> x(n);
    for(auto &i : x)cin >> i;
    sort(x.begin(), x.end());

    vector<size_t> ans;
    unordered_set<size_t> visited;
    for(auto &i : x)
    {
        size_t s = ans.size();
        for(size_t j = 0; j < s; j++)
        {
            if(visited.find(ans[j]+i) == visited.end())
            {
                visited.insert(ans[j]+i);
                ans.push_back(ans[j]+i);
            }
        }
        if(visited.find(i) == visited.end())
        {
            visited.insert(i);
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &i : ans)cout << i << ' ';
}