#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")

using ll = long long;
using ull = unsigned long long;

const int n = 8, P_END = n*n;
vector<bool> dag(n*2, true);
vector<bool> disdag(n*2, true);
vector<bool> x(n, true);
vector<bool> y(n, true);
vector<vector<char>> graph(n, vector<char>(n));

void dfs(int &p, int &rem, int &ans)
{
    if(rem == 0)
    {
        ans++;
        return;
    }
    if(p == P_END)return;
    int px = p/n, py = p%n;
    p++;
    dfs(p, rem, ans);
    if(graph[px][py] == '.')if(dag[px+py] && disdag[n+px-py] && x[px] && y[py])
    {
        dag[px+py] = disdag[n+px-py] = x[px] = y[py] = false;
        rem--;
        dfs(p, rem, ans);
        rem++;
        dag[px+py] = disdag[n+px-py] = x[px] = y[py] = true;
    }
    p--;
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    for(auto &i : graph)for(auto &j : i)cin >> j;
    int ans = 0, p = 0, rem = 8;
    dfs(p, rem, ans);
    cout << ans;
}