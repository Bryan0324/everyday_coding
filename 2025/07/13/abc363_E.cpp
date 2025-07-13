#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


typedef pair<int, int> Pos;

// debug
// #define cerr //
const int INF = 1e6;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int h, w, fyear;
    cin >> h >> w >> fyear;
    int area = h*w;
    vector<vector<int>> graph(h+2, vector<int>(w+2, INF));
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> graph[i][j];
        }
    }
    Pos ways[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, greater<>> pq;
    for(int i = 1; i <= h; i++)
    {
        if(graph[i][1] != INF)pq.push({graph[i][1], {i, 1}});
        graph[i][1] = INF;
        if(graph[i][w] != INF)pq.push({graph[i][w], {i, w}});
        graph[i][w] = INF;
    }
    for(int i = 1; i <= w; i++)
    {
        if(graph[1][i] != INF)pq.push({graph[1][i], {1, i}});
        graph[1][i] = INF;
        if(graph[h][i] != INF)pq.push({graph[h][i], {h, i}});
        graph[h][i] = INF;
    }

    for(int year = 1; year <= fyear; year++)
    {
        while(!pq.empty())
        {
            auto top = pq.top();
            if(top.first > year)break;
            pq.pop();
            area--;
            auto &[x, y] = top.second;
            for(size_t d = 0; d < 4; d++)
            {
                auto &[dx, dy] = ways[d];
                //cerr << x+dx << ' ' << y+dy << '\n';
                auto &dnow = graph[x+dx][y+dy];
                if(dnow == INF)continue;
                pq.push({dnow, {x+dx, y+dy}});
                dnow = INF;
            }
        }
        cout << area << '\n';
    }
}