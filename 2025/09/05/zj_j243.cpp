#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

struct Data
{
    vector<ll> v;
    int d;
    Data(int _d = 1):d(_d), v(_d){};

    ull operator-(const Data &b)
    {
        ull ans = 0;
        for (ull i = 0; i < v.size(); i++)
        {
            ans += abs(v[i] - b.v[i]);
        }
        return ans;
    }
};

struct DSU
{
    vector<ull> boss, size;
    DSU(ull _size):boss(_size), size(_size, 1)
    {
        for (ull i = 0; i < _size; i++)
        {
            boss[i] = i;
        }
    }
    ull find(ull q)
    {
        if(boss[q] != q)boss[q] = find(boss[q]);
        return boss[q];
    }
    void merge(ull a, ull b)
    {
        a = find(a); b = find(b);
        if(size[a] < size[b])swap(a, b);
        boss[b] = a;
        size[a] += size[b];
        return;
    }
};

typedef pair<ull, pair<ull, ull>> Side;
#define weight first
#define left second.first
#define right second.second
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int d, n;
    cin >> d >> n;
    vector<Data> all(n, Data(d));
    for(auto &i : all)for(auto &j : i.v)cin >> j;

    vector<vector<ull>> graph(n, vector<ull>(n));
    DSU s(n);
    priority_queue<Side, vector<Side>, greater<>> pq;

    for (ull i = 0; i < n; i++)
    {
        for (ull j = i+1; j < n; j++)
        {
            graph[i][j] = graph[j][i] = all[i] - all[j];
            pq.push({graph[i][j], {i, j}});
        }
    }
    ll before = pq.top().weight;
    ull k = n;
    while(true)
    {
        auto &now = pq.top();
        if(s.find(now.left) == s.find(now.right))
        {
            pq.pop();
            continue;
        }
        s.merge(now.left, now.right);
        k--;
        pq.pop();
        if(before == pq.top().weight)break;
        before = pq.top().weight;
    }
    cout << k+1;
}