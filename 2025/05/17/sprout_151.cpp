#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long
#define size_t unsigned long long

void solve()
{
    size_t n, m, a, b;
    cin >> n >> m;
    vector<vector<size_t>> graph(n);
    vector<size_t> iangle(n);
    vector<size_t> ans;
    while(m--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        iangle[b]++;
    }
    priority_queue<size_t, vector<size_t>, greater<>> pq;
    for(size_t i = 0; i < n; i++)if(iangle[i] == 0)pq.push(i);

    while(!pq.empty())
    {
        ans.push_back(pq.top());
        auto &i = ans.back();
        pq.pop();
        for(auto &j : graph[i])
        {
            --iangle[j];
            if(iangle[j] == 0)pq.push(j);
        }
    }
    if(ans.size() != n)cout << "QAQ";
    else for(auto &i : ans)cout << i << ' ';
    cout << '\n';
}


int main()
{
    size_t t;
    cin >> t;
    while(t--)solve();
}

