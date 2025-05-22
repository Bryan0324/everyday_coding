#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second

typedef pair<size_t, size_t> edge;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    size_t n;
    ssize_t tmp;
    cin >> n;
    vector<vector<size_t>> graph(n, vector(n, 0ull));
    for(auto &i : graph)for(auto &j : i)
    {
        cin >> tmp;
        if(tmp == -1)j = LLONG_MAX;
        else j = tmp;
    }
    int ans = 0;
    //cout << ans << '\n';
    for (size_t now = 0; now < n; now++)
    {
        for (size_t k = 0; k <= now; k++)
        {
            for(size_t i = now; i == now; i++)
            {
                for(size_t j = 0; j <= now; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
        for (size_t k = 0; k <= now; k++)
        {
            for(size_t i = 0; i <= now; i++)
            {
                for(size_t j = now; j == now; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }

        for (size_t k = now; k == now; k++)
        {
            for(size_t i = 0; i <= now; i++)
            {
                for(size_t j = 0; j <= now; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }

        ans = 0;
/*         for(size_t i = 0; i <= now; i++)
        {
            for(size_t j = 0; j <= now; j++)cerr << (graph[i][j] >= LLONG_MAX ? "X" : to_string(graph[i][j])) << ' ';
            cerr << '\n';
        } */
        for(size_t i = 0; i <= now; i++)
        {
            for(size_t j = 0; j <= now; j++)
            {
                if(graph[i][j] >= LLONG_MAX)
                {
                    ans = -1;
                    i = now;
                    break;
                }
                if(ans < graph[i][j])ans = graph[i][j];
            }
        }
        cout << ans << ' ';
    }
    
}
