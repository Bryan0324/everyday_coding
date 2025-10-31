#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> path;
#define val first
#define to second

int n, m1, m2;
int startp, endp;
const int INF = INT_MAX;
int dijk(vector<vector<path>> &one, vector<vector<path>> &second)
{
    vector<vector<int>> turned(2, vector<int>(n, INF));
    turned[0][startp] = turned[1][startp] = 0;
    priority_queue<pair<path, int>, vector<pair<path, int>>, greater<>> pq;
    pq.push({{0, startp}, 0});
    while(!pq.empty())
    {
        auto [top, t] = pq.top();
        pq.pop();
        if(!t)for(auto &i : one[top.to])
        {
            if(top.val+i.val < turned[0][i.to])
            {
                turned[0][i.to] = top.val+i.val;
                pq.push({{top.val+i.val, i.to}, 0});
            }
        }

        for(auto &i : second[top.to])
        {
            if(top.val+i.val < turned[1][i.to])
            {
                turned[1][i.to] = top.val+i.val;
                pq.push({{top.val+i.val, i.to}, 1});
            }
        }
    }
    return min(turned[0][endp], turned[1][endp]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int u, v, c;
    cin >> n >> m1 >> m2;

    vector<vector<path>> one(n), second(n);
    while(m1--)
    {
        cin >> u >> v >> c;
        one[u].push_back({c, v});
        one[v].push_back({c, u});
    }
    while(m2--)
    {
        cin >> u >> v >> c;
        second[u].push_back({c, v});
        second[v].push_back({c, u});
    }
    cin >> startp >> endp;
    cout << min(dijk(one, second), dijk(second, one));
}