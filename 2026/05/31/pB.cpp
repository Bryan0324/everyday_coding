#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pos;
const pos ZERO = {0, 0};
unordered_map<char, pos> dirs = {
    {'U', {0, 1}},
    {'R', {1, 0}},
    {'L', {-1, 0}},
    {'D', {0, -1}}
};
unordered_map<char, string> to_s = {
    {'U', "UP"},
    {'R', "RIGHT"},
    {'L', "LEFT"},
    {'D', "DOWN"}
};
#define x first
#define y second

pos operator+(const pos &a, const pos &b)
{
    return {a.first+b.first, a.second+b.second};
}

int alpha(ull &n)
{
    cout << n-1 << endl;
    for(int i = 0; i < n; i++)
    {
        pos now = ZERO;
        string op = "S";
        for(int j = 0; j < i; j++)
        {
            now = now + dirs['R'];
            cout << "RIGHT" << endl;
            cin >> op;
        }
        while(op[0] == 'S')
        {
            now = now + dirs['U'];
            cout << "UP" << endl;
            cin >> op;
        }
        if(op[0] == 'G')return 0;
    }
    return 0;
}

bool beta(ull &n, vector<vector<char>> &graph)
{
    
    cout << __lg(n-2)+2 << endl;
    auto run = [&](int i)->int
    {
        pos now = ZERO;
        string op = "S";
        for(int j = 0; j < i; j++)
        {
            now = now + dirs['R'];
            cout << "RIGHT" << endl;
            cin >> op;
        }
        while(op[0] == 'S')
        {
            graph[now.x][now.y] = 'O';
            now = now + dirs['U'];
            cout << "UP" << endl;
            cin >> op;
        }
        if(op[0] == 'G')return n;
        for(int i = 0; i < n; i++)
        {
            if(i != now.x)graph[i][now.y] = 'O';
            if(i != now.y)graph[now.x][i] = 'O';
        }
        return now.y;
    };
    vector<int> len(n);
    len[0] = run(0);
    if(len[0] == n)return true;
    len[n-1] = run(n-1);
    if(len[n-1] == n)return true;
    for(int l = 0, r = n-1; abs(len[r] - len[l]) > 1; )
    {
        int mid = (l+r)/2;
        len[mid] = run(mid);
        if(len[mid] == n)return true;
        if((len[r]-len[mid] < 0) != (len[mid]-len[l] < 0))return true;
        if(abs(len[r]-len[mid]) < abs(len[mid]-len[l]))l = mid;
        else r = mid;
    }
    
    return false;
}


bool dfs(const pos &now, vector<vector<char>> &graph, string &s)
{
    int n = graph.size();
    if(now.y == n-1)return true;
    for(auto &i : dirs)
    {
        auto next = now + i.second;
        if(0 > next.x || next.x >= n)continue;
        if(0 > next.y || next.y >= n)continue;
        if(graph[next.x][next.y] != 'O')continue;
        s.push_back(i.first);
        graph[next.x][next.y] = 'X';
        if(dfs(next, graph, s))return true;
        graph[next.x][next.y] = 'O';
        s.pop_back();
    }
    return false;
};

int main()
{

    ull n;
    cin >> n;
    if(n == 3 || n == 4)return alpha(n);
    vector<vector<char>> graph(n, vector<char>(n, 'X'));
    for(auto &i : graph)i[0] = 'O';
    if(beta(n, graph))return 0;
    string s;

    dfs(ZERO, graph, s);
    for(auto &i : s)cout << to_s[i] << endl;
}

/* 

queue<pos> bfs;
    bfs.push(ZERO);
    while(!bfs.empty())
    {
        auto now = bfs.front();
        bfs.pop();
        if(now.y == n-1)break;
        for(auto &i : dirs)
        {
            auto next = now + i.second;
            if(0 > next.x || next.x >= n)continue;
            if(0 > next.y || next.y >= n)continue;
            if(graph[next.x][next.y] != 'O')continue;
            graph[next.x][next.y] = i.first;
            bfs.push(next);
        }
    }
    
    pos now = ZERO;
    string op = "S";
    while(op[0] == 'S')
    {
        
    }
*/