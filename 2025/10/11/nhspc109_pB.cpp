#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ll, ll> path; 
#define v first
#define connect second

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    
    ll a, b, c;
    vector<vector<path>> graph(n);
    vector<ll> indeg(n);
    while(m--)
    {
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c, b});
        indeg[b]++;
    }
    queue<int> topo_q;
    for(int i = 0; i < n; i++)if(indeg[i] == 0)topo_q.push(i);
    vector<ll> dangerous(n, LLONG_MAX/4);
    dangerous[0] = 0;
    ll ans = 0;
    while(!topo_q.empty())
    {
        auto front = topo_q.front();
        topo_q.pop();
        ans += dangerous[front];
        for(auto &i : graph[front])
        {
            dangerous[i.connect] = min(dangerous[i.connect], dangerous[front] + i.v);
            indeg[i.connect]--;
            if(indeg[i.connect] == 0)topo_q.push(i.connect);
        }
    }
    cout << ans;
}


/* SPFA版

#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ll, ll> path; 
#define v first
#define connect second

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    
    ll a, b, c;
    vector<vector<path>> graph(n);
    while(m--)
    {
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c, b});
    }
    vector<ll> dangerous(n, LLONG_MAX/4);
    dangerous[0] = 0;
    deque<int> relax;
    vector<bool> in_queue(n, false);

    relax.push_back(0);
    in_queue[0] = true;

    while(!relax.empty())
    {
        auto front = relax.front();
        relax.pop_front();
        in_queue[front] = false;
        for(auto &i : graph[front])
        {
            if(dangerous[front]+i.v < dangerous[i.connect])
            {
                dangerous[i.connect] = dangerous[front]+i.v;
                if(!in_queue[i.connect])
                {
                    if(dangerous[i.connect] > dangerous[front])relax.push_back(i.connect);
                    else relax.push_front(i.connect);
                }
                in_queue[i.connect] = true;
            }
        }
    }
    ll ans = 0;
    for(auto &i : dangerous)ans += i;
    cout << ans;
}

*/