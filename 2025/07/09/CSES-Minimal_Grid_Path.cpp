#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


#define x first
#define y second

// debug
// #define cerr //

inline char &place(vector<string> &graph, pair<size_t, size_t> &p)
{
    return graph[p.x][p.y];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n;
    cin >> n;
    vector<string> graph(n);
    for(auto &i : graph)
    {
        cin >> i;
        i += 'Z'+1;
    }
    graph.push_back(string(n+1, 'Z'+1));

    vector<pair<size_t, size_t>> nows = {{0, 0}};
    cout << graph[0][0];
    for (size_t i = 1; i < n*2-1; i++)
    {
        vector<pair<size_t, size_t>> tmp = {};
        char c = 'Z'+1;
        for(auto &now : nows)
        {
            auto a = now;
            a.x++;
            if(place(graph, a) != 'Z'+1)
            {
                if(c == place(graph, a))
                {
                    tmp.push_back(a);
                }
                else if(c > place(graph, a))
                {
                    tmp = {a};
                    c = place(graph, a);
                }
            }
            place(graph, a) = 'Z'+1;
            auto b = now;
            b.y++;
            if(place(graph, b) != 'Z'+1)
            {
                if(c == place(graph, b))
                {
                    tmp.push_back(b);
                }
                else if(c > place(graph, b))
                {
                    tmp = {b};
                    c = place(graph, b);
                }
            }
            place(graph, b) = 'Z'+1;
        }
        cout << c;
        nows = tmp;
    }
}