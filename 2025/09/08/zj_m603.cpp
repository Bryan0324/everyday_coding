#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

typedef pair<int, int> Pos;
#define x first
#define y second

Pos operator-(Pos a, Pos b)
{
    return {a.x-b.x, a.y-b.y};
}
int operator^(Pos a, Pos b)
{
    return a.x*b.y - a.y*b.x;
}
int triangle_area(Pos p, Pos a, Pos b)
{
    return (a - p) ^ (b - p);
}

int solve()
{
    int n, m, ans = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));
    for(auto &i : graph)for(auto &j : i)cin >> j;

    for(int i = 0; i < n-2; i++)
    {
        for(int j = 0; j < m-2; j++)
        {
            if(graph[i][j] == 1)
            {
                ans++;
                for(int di = 0; di < 3; di++)
                {
                    for(int dj = 0; dj < 3; dj++)
                    {
                        graph[i+di][j+dj] = (graph[i+di][j+dj]+1)&1;
                    }
                }
            }
        }
    }
    for(auto &i : graph)for(auto &j : i)if(j == 1)return -1;
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    cout << solve();
}