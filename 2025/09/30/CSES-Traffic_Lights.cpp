#include<bits/stdc++.h>
using namespace std;
 
 
 
 
using ull = unsigned long long;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int x, n; 
    cin >> x >> n;
    vector<int> p(n);
    for(auto &i : p)cin >> i;
    multiset<int> road;
    set<int> pos;
    pos.insert(0);
    pos.insert(x);
    road.insert(x);
    for(auto &i : p)
    {
        auto front = next(pos.lower_bound(i), -1);
        auto back = pos.upper_bound(i);
        road.erase(road.find(*back - *front));
        road.insert(i - *front);
        road.insert(*back - i);
        pos.insert(i);
        cout << *next(road.end(), -1) << ' ';
    }
}
