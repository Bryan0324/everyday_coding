#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
typedef pair<int, int> Pos;
#define x first
#define y second
 
int start = 0;
 
bool cmp(deque<int> &a, deque<int> &b)
{
    for(int i = start; i < min(a.size(), b.size()); i++)
    {
        if(a[i] == b[i])continue;
        return a[i] > b[i];
    }
    return a.size() > b.size();
}
 
void solve()
{
    start = 0;
    int n, k;
    cin >> n;
    vector<deque<int>> as(n);
    for(auto &i : as)
    {
        cin >> k;
        i.resize(k);
        for(auto &j : i)cin >> j;
    }
    vector<int> ans;
    while(!as.empty())
    {
        sort(as.begin(), as.end(), cmp);
        while(!as.empty())
        {
            if(as.back().size() <= ans.size())as.pop_back();
            else break;
        }
        if(as.empty())break;
        for(start; start < as.back().size(); start++)
        {
            ans.push_back(as.back()[start]);
        }
        as.pop_back();
    }
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