#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

const ull MOD = 1e9+7;

vector<vector<int>> graph;
vector<vector<ull>> dp;

#define BLACK 0
#define WHITE 1

void dfs(int n, int from = 0)
{
    for(auto &i : graph[n])
    {
        if(i == from)continue;
        dfs(i, n);
        dp[BLACK][n] *= dp[WHITE][i];
        dp[WHITE][n] *= (dp[BLACK][i]+dp[WHITE][i]) %MOD;
        dp[BLACK][n] %=MOD;
        dp[WHITE][n] %=MOD;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    graph.resize(n);
    dp.resize(2, vector<ull>(n, 1));
    for(int x, y, i = 1; i < n; i++)
    {
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(0);

    cout << (dp[WHITE][0] + dp[BLACK][0]) %MOD;
}