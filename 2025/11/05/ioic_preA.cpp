#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

typedef pair<ull, ull> pq_unit;
#define poull first
#define idx second
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ull n, k;
    cin >> n >> k;
    vector<ull> a(n), w(n);
    for(auto &i : a)cin >> i;
    for(auto &i : w)cin >> i;
    priority_queue<pq_unit> pq;
    for(ull i = 0; i < n; i++)
    {
        pq.push({(a[i]+1)/2*w[i], i});
    }
    while(k-- && !pq.empty())
    {
        auto &top = pq.top();
        a[top.idx] /= 2;
        if(a[top.idx])pq.push({(a[top.idx]+1)/2*w[top.idx], top.idx});
        pq.pop();
    }
    ull ans = 0;
    for (ull i = 0; i < n; i++)
    {
        ans += a[i]*w[i];
    }
    cout << ans;
}
