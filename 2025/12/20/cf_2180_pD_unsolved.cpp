#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ll, pair<ll, ll>> pq_unit;
void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    for(auto &i : x)
    {
        cin >> i;
        i *= 2;
    }
    vector<int> size(n);
    priority_queue<pq_unit, vector<pq_unit>, greater<>> pq;
    for(int i = 0; i < n-1; i++)
    {
        pq.push({(x[i+1]-x[i]), {i, i+1}});
    }
    int ans = 0;
    while(!pq.empty())
    {
        queue<pair<int, int>> q;
        auto [len, start] = pq.top();
        pq.pop();
        if(size[start.first] || size[start.second])continue;
        ans++;
        q.push({start.first, -1});
        q.push({start.second, 1});
        size[start.first] = size[start.second] = len/2;
        while(!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            if(a+b < 0 || a+b >= n || size[a+b])continue;
            if(abs(x[a+b]-x[a])-size[a] >= abs(x[a+b+b]-x[a+b])-size[a+b+b])continue;

            size[a+b] = abs(x[a+b]-x[a])-size[a];
            ans++;

            q.push({a+b, b});
        }
    }
    

    cout << ans << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}