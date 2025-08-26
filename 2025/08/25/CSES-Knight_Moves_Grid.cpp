#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")

using ll = long long;
using ull = unsigned long long;

struct G: vector<vector<int>>
{
    int null_pos = -2;
    G(int n, int m, int item = 0)
    {
        this->resize(n);
        for(auto &i : *this)i.resize(m, item);
    }
    int &at(int n, int m)
    {
        if(n < 0 || m < 0)return null_pos;
        if(n >= this->size() || m >= (*this)[0].size())return null_pos;
        return (*this)[n][m];
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    G graph(n, n, -1);
    queue<pair<int, int>> bfs;
    graph.at(0, 0) = 0;
    bfs.push({0, 0});
    while(!bfs.empty())
    {
        auto &[x, y] = bfs.front();
        int now = graph.at(x, y);
        for(auto &dx : {1, -1})
        {
            for(auto &dy : {1, -1})
            {
                if(graph.at(x+dx, y+dy*2) == -1)
                {
                    graph.at(x+dx, y+dy*2) = now+1;
                    bfs.push({x+dx, y+dy*2});
                }
                if(graph.at(x+dx*2, y+dy) == -1)
                {
                    graph.at(x+dx*2, y+dy) = now+1;
                    bfs.push({x+dx*2, y+dy});
                }
            }
        }
        bfs.pop();
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