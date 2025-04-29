#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
vector<vector<bool>> canva;
 
void dfs(size_t i, size_t j)
{
    canva[i][j] = false;
    if(canva[i-1][j])dfs(i-1, j);
    if(canva[i+1][j])dfs(i+1, j);
    if(canva[i][j-1])dfs(i, j-1);
    if(canva[i][j+1])dfs(i, j+1);
    return;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n, m;
    cin >> n >> m;
    canva = vector<vector<bool>>(n+2, vector(m+2, false));
    char c;
    for(size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            cin >> c;
            if(c == '.')canva[i][j] = true;
        }
    }
    size_t ans = 0;
    for(size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            if(canva[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}
