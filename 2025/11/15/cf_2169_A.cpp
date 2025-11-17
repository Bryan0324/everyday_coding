//https://codeforces.com/contest/2169/problem/A
#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;
 
typedef pair<int, int> tl;
#define val first
#define p second
void solve()
{
    
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
 
    vector<tl> timeline(n*2);
    for(int i = 0; i < n; i++)
    {
        if(v[i] > a)
        {
            timeline[i] = {a+1, 1};
            timeline[i+n] = {v[i]*2-a, -1};
        }else
        {
            timeline[i] = {max(v[i]*2-a+1, 0), 1};
            timeline[i+n] = {a, -1};
        }
    }
    sort(timeline.begin(), timeline.end());
    int ans = -1, now = 0, idx = 0;
    for(auto &i : timeline)
    {
        now += i.p;
        if(now > ans)
        {
            now = ans;
            idx = i.val;
        }
    }
    cout << idx << '\n';
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}