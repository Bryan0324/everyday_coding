#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")

using ll = long long;
using ull = unsigned long long;

int MEX(vector<vector<bool>> &col, vector<vector<bool>> &row, int i, int j)
{
    int n;
    for (; col[i][n] || row[j][n]; n++);
    col[i][n] = row[j][n] = true;
    return n;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<bool>> col(n, vector<bool>(n*2-1)), row(n, vector<bool>(n*2-1));
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = MEX(col, row, i, j);
        }
    }
    for(auto &i : graph)
    {
        for(auto &j : i)cout << j << ' ';
        cout << '\n';
    }
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