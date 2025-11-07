#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

typedef pair<int, int> Pos;
#define x first
#define y second

int sum(Pos start, Pos end, vector<vector<int>> &p)
{
    return p[start.x][start.y] - p[end.x][start.y] - p[start.x][end.y] + p[end.x][end.y];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    char tmp;
    for(auto &i : graph)for(auto &j : i)
    {
        cin >> tmp;
        j = tmp-'0';
    }
    vector<vector<int>> presum(n+1, vector<int>(n+1)), zeros(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)
    {
        presum[i][j] = graph[i-1][j-1] + presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
        zeros[i][j] = zeros[i-1][j] + zeros[i][j-1] - zeros[i-1][j-1];
        if(!graph[i-1][j-1])zeros[i][j]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        Pos ptr = {i-1, 0};
        for (Pos now = {i, 1}; now.x <= n; now.x++, now.y++)
        {
            while(ptr != now)
            {
                if(!sum(now, ptr, zeros))break;
                ptr.x++; ptr.y++;
            }
            if(ptr != now)ans = max(ans, sum(now, ptr, presum));
        }
    }
    for(int i = 1; i <= n; i++)
    {
        Pos ptr = {0, i-1};
        for (Pos now = {1, i}; now.y <= n; now.x++, now.y++)
        {
            while(ptr != now)
            {
                if(!sum(now, ptr, zeros))break;
                ptr.x++; ptr.y++;
            }
            if(ptr != now)ans = max(ans, sum(now, ptr, presum));
        }
    }
    cout << ans;
}