#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
struct node
{
    vector<node*> child;
};
 
vector<node> comp;
 
void dfs(vector<size_t> &ans, size_t now = 0)
{
    size_t tmp = 1;
    if(comp[now].child.size() == 0)
    {
        ans[now] = 1;
        return;
    }
    for(auto &i : comp[now].child)
    {
        if(ans[&(*i)-&comp[0]] == 0)dfs(ans, &(*i)-&comp[0]);
        tmp += ans[&(*i)-&comp[0]];
    }
    ans[now] = tmp;
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, k;
    cin >> n;
    comp = vector<node>(n);
    for (size_t i = 1; i < n; i++)
    {
        cin >> k;
        --k;
        comp[k].child.push_back(&comp[i]);
    }
    vector<size_t> ans(n);
    dfs(ans);
    for(auto &i : ans)cout << i-1 << ' ';
    return 0;
}
