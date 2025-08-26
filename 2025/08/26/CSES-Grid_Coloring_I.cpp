#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")
 
int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n+2, vector<char>(m+2, '#'));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    bool t = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t = true;
            for (char c = 'A'; c <= 'D'; c++)
            {
                if(graph[i][j] == c || graph[i][j-1] == c || graph[i-1][j] == c)continue;
                graph[i][j] = c;
                t = false;
                break;
            }
            if(t)return -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << graph[i][j];
        }
        cout << '\n';
    }
    return 0;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if(solve() == -1)cout << "INPOSSIBLE";
}
/* 
0
 
0 1
1 0
 
0 1 2
2 0 1
1 2 0
 
0 1 2 3
0 3 1 2
 
*/