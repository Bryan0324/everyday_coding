#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, m, a, b;
    cin >> n >> m;
    vector<vector<size_t>> graph(n);
    while(m--)
    {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<size_t> ans(n);
    for(size_t i = 0; i < n; i++)
    {
        if(ans[i] != 0)continue;
        queue<size_t> bfs;
        ans[i] = 1;
        bfs.push(i);
        while(!bfs.empty())
        {
            auto &now = bfs.front();
            auto next = (ans[now] == 1 ? 2 : 1);
            for(auto &j : graph[now])
            {
                if(ans[j] == 0)
                {
                    ans[j] = next;
                    bfs.push(j);
                }else if(ans[j] != next)
                {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
            bfs.pop();
        }
    }
    for(auto &i : ans)cout << i << ' ';
    return 0;
}
