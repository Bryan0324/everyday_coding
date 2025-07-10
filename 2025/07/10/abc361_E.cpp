#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

typedef pair<size_t, int> side;
#define value first
#define to second

int main() {
    int n; 
    cin >> n;
    vector<vector<side>> graph(n);
    size_t sum = 0, a, b, c;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
        sum += c;
    }
    sum <<= 1;

    queue<side> bfs;
    vector<bool> visited;
    side far = {0, 0};
    for(size_t j = 0; j < 2; j++)
    {
        far = {0, far.to};
        bfs.push(far);
        visited = vector<bool>(n, false);
        visited[far.to] = true;
        while(!bfs.empty())
        {
            auto &f = bfs.front();
            //cerr << f.value << ' ' << f.to << "]\n";
            if(f.value > far.value)far = f;
            for(auto &i : graph[f.to])
            {
                if(!visited[i.to])
                {
                    bfs.push({i.value+f.value, i.to});
                    visited[i.to] = true;
                }
            }
            bfs.pop();
        }
    }
    cout << sum - far.value;
}