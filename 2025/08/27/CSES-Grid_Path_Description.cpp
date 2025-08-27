#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("O3")
 
using ull = unsigned long long;
 
#define x first
#define y second
typedef pair<int, int> Pos;
Pos operator+(Pos &a, Pos &b)
{
    return {a.x+b.x, a.y+b.y};
}
 
const int n = 7;
vector<vector<bool>> visited(n+2, vector<bool>(n+2, true));
 
unordered_map<char, Pos> ways = {
    {'R', {0, 1}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
};
vector<Pos> w = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
int dfs(string &s, int idx, Pos p)
{
    if(idx == s.size())return (p.x == 7 && p.y == 1 ? 1 : 0);
    if(p.x == 7 && p.y == 1)return 0;
    if(visited[p.x-1][p.y] && visited[p.x+1][p.y])
    {
        if(!visited[p.x][p.y-1] && !visited[p.x][p.y+1])return 0;
    }
    if(visited[p.x][p.y-1] && visited[p.x][p.y+1])
    {
        if(!visited[p.x-1][p.y] && !visited[p.x+1][p.y])return 0;
    }

    for(int i = 0; i < 4; i++)
    {
        auto &d1 = w[i%4];
        auto &d2 = w[(i+1)%4];
        if(!visited[p.x + d1.x][p.y + d1.y] && !visited[p.x + d2.x][p.y + d2.y])
        {
            if(visited[p.x + d1.x + d2.x][p.y + d1.y + d2.y])return 0;
        }
    }

    int ans = 0;
    if(s[idx] == '?')
    {
        for(auto &i : w)
        {
            auto next = i+p;
            if(!visited[next.x][next.y])
            {
                visited[next.x][next.y] = true;
                ans += dfs(s, idx+1, next);
                visited[next.x][next.y] = false;
            }
        }
    }else
    {
        auto next = ways[s[idx]]+p;
        if(!visited[next.x][next.y])
        {
            visited[next.x][next.y] = true;
            ans += dfs(s, idx+1, next);
            visited[next.x][next.y] = false;
        } 
    }
    return ans;
}
 
 
int main()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = false;
        }
    }
    string s;
    cin >> s;
    visited[1][1] = true;
    cout << dfs(s, 0, {1, 1});
}