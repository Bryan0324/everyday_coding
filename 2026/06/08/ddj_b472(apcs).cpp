#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int T = 0, t;

int n, m, k, r;

vector<int> ans;

bool dfs(unordered_set<int> &visited, vector<vector<int>> &a, const int i = 0, const int i_cnt = 0, const int j = 0)
{
    if(visited.size() == k)
    {
        if(++T == t)return true;
        return false;
    }

    if(i == m)return false;
    if(j == r || i_cnt == 2)return dfs(visited, a, i+1);

    if(visited.count(a[i][j]))return dfs(visited, a, i, i_cnt, j+1);

    visited.insert(a[i][j]);
    if(dfs(visited, a, i, i_cnt+1, j+1))
    {
        ans.push_back(i*r+j+1);
        return true;
    }
    visited.erase(a[i][j]);

    return dfs(visited, a, i, i_cnt, j+1);

};
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> r >> k >> t;
    vector<vector<int>> a(m, vector<int>(r));
    for(auto &i : a)for(auto &j : i)cin >> j;

    unordered_set<int> visited;
    dfs(visited, a);
    for(int i = ans.size(); i > 0; i--)cout << ans[i-1] << ' ';
}