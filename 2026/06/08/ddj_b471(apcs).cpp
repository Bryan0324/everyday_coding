#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

#define s first
#define e second

const int PEOPLE = 0;
const int IN = -1;
const int OUT = 1;

#define time first
#define type second

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ull n, m;
    cin >> n >> m;
    vector<pair<int, int>> se(m);
    vector<int> d(n);
    for(auto &i : d)cin >> i;
    for(auto &i : se)cin >> i.s >> i.e;

    vector<pair<int, int>> timeline;
    for(auto &i : d)timeline.push_back({i, PEOPLE});
    for(auto &i : se)
    {
        timeline.push_back({i.s, IN});
        timeline.push_back({i.e, OUT});
    }
    sort(timeline.begin(), timeline.end());
    ull ans = 0, cnt = 0;
    for(auto &t : timeline)
    {
        if(t.type == PEOPLE)ans += cnt;
        else cnt -= t.type;
    }
    cout << ans;
}