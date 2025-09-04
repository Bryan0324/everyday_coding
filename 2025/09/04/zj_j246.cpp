#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<ll, pair<ll, ll>> Job;
#define t first
#define pos second.first
#define c second.second

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ll n, k, x;
    cin >> n >> k >> x;
    x--;
    ll systime = 0;
    Job job;
    vector<Job> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].t >> v[i].c;
        v[i].pos = i;
    }
    ll ptr = 0;
    queue<Job> q;

    while(true)
    {
        if(q.empty())q.push(v[ptr++]);
        auto &now = q.front();
        //cerr << now.t << ' ' << now.c << '\n';
        if(systime < now.t)systime = now.t;
        systime += min(k, now.c);
        now.c = max(0ll, now.c-k);
        if(now.pos == x && now.c == 0)break;
        while(ptr != v.size())
        {
            if(systime > v[ptr].t)q.push(v[ptr++]);
            else break;
        }
        
        if(now.c != 0)q.push(now);
        q.pop();
    }
    cout << systime - q.front().t;
}
