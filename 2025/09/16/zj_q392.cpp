#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MAX_D = 1e6+10;
typedef pair<pair<ull, ull>, int> path;
#define len first.first
#define money first.second
#define to second

path operator+(path &a, path &b)
{
    return {{a.len+b.len, a.money+b.money}, b.to};
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int a, start, end, t;
    cin >> a >> start >> end;
    start--; end--;
    vector<vector<path>> graph(MAX_D);
    vector<vector<path>> no_money(MAX_D);
    path tmpin;
    while(a--)
    {
        cin >> tmpin.to >> t >> tmpin.len >> tmpin.money;
        tmpin.to--;
        t--;
        graph[t].push_back(tmpin);
        if(tmpin.money == 0)no_money[t].push_back(tmpin);
        swap(tmpin.to, t);
        graph[t].push_back(tmpin);
        if(tmpin.money == 0)no_money[t].push_back(tmpin);
    }
    vector<path> ans_have_money(MAX_D, {{0, 0}, -1});
    priority_queue<path, vector<path>, greater<>> pq;
    pq.push({{0, 0}, start});
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans_have_money[top.to] = top;
        if(top.to == end)break;
        for(auto &p : graph[top.to])
        {
            if(ans_have_money[p.to].to == -1)
            {
                pq.push(top+p);
            }
        }
    }
    if(ans_have_money[end].to != -1)cout << ans_have_money[end].len << ' ' << ans_have_money[end].money << ' ';
    else cout << "-1 -1 ";

    vector<path> ans_free(MAX_D, {{0, 0}, -1});
    pq = priority_queue<path, vector<path>, greater<>>();
    pq.push({{0, 0}, start});
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans_free[top.to] = top;
        if(top.to == end)break;
        for(auto &p : no_money[top.to])
        {
            if(ans_free[p.to].to == -1)
            {
                pq.push(top+p);
            }
        }
    }
    if(ans_free[end].to != -1)cout << ans_free[end].len << '\n';
    else cout << "-1\n";
    return 0;
}