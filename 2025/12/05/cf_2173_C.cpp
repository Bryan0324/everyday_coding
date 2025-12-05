#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> pq_unit;
#define now first
#define add second

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> _a(n);
    for(auto &i : _a)cin >> i;
    sort(_a.begin(), _a.end());
    vector<int> a(_a.begin(), unique(_a.begin(), _a.end()));
    
    priority_queue<pq_unit, vector<pq_unit>, greater<>> pq;
    pq.push({a[0], a[0]});
    for(auto &i : a)
    {
        bool con = false;
        if(pq.top().now < i)
        {
            cout << "-1\n";
            return;
        }
        while(pq.top().now == i)
        {
            con = true;
            pq.push({pq.top().now+pq.top().add, pq.top().add});
            pq.pop();
        }
        if(!con)pq.push({i+i, i});
    }
    if(pq.top().now <= k)
    {
        cout << "-1\n";
        return;
    }
    cout << pq.size() << '\n';
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().add);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for(auto &i : ans)cout << i << ' ';
    cout << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        solve();   
    }
}

