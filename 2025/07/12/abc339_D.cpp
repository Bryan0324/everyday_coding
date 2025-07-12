#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


#define x first
#define y second

// debug
// #define cerr //

typedef pair<int, int> Pos;

const int magic = 70;
bool _visited[(60*magic+60)*magic*magic + (60*magic+60)+1] = {};

bool& visited(int &i, int &j)
{
    return _visited[i*magic*magic+j];
}

int ways[4] = 
{
    1*magic,  //down
    1,      //right
    -1*magic, //up
    -1,     //left
};
int walk(int m, vector<vector<char>> &graph, int dir)
{
    m += ways[dir];
    if(graph[m/magic][m%magic] == '#')m -= ways[dir];
    return m;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> players;
    vector<vector<char>> graph(n+2, vector<char>(n+2, '#'));
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)
    {
        cin >> graph[i][j];
        if(graph[i][j] == 'P')players.push_back(i*magic + j);
    }
    queue<vector<int>> bfs;

    bfs.push({0, players[0], players[1]});
    while(!bfs.empty())
    {
        auto now = bfs.front();
/*         cerr << "##########" << now[0] << "###########\n";
        for(int i = 0; i <= n+1; i++)
        {
            for(int j = 0; j <= n+1; j++)
            {
                if(i*magic + j == now[1])cerr << 'P';
                else if(i*magic + j == now[2])cerr << 'P';
                else if(graph[i][j] == '#')cerr << '#';
                else cerr << ' ';
            }
            cerr << '\n';
        }
        cerr << "######################";
        cin >> players[0]; */
        if(now[1] == now[2])break;
        now[0]++;
        if(!visited(now[1], now[2]))
        {
            visited(now[1], now[2]) = true;
            for(size_t i = 0; i < 4; i++)
            {
                bfs.push({now[0], walk(now[1], graph, i), walk(now[2], graph, i)});
            }
        }
        bfs.pop();
    }
    if(bfs.empty())cout << "-1";
    else cout << bfs.front()[0];
}
/* 
..P.#
###..
P.##.
.#...
....#

*/