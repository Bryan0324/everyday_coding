#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
typedef pair<int, pair<int, int>> project;
#define end_day first
#define start_day second.second
#define money second.first
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<project> p(n);
    for(auto &i : p)cin >> i.start_day >> i.end_day >> i.money;
    sort(p.begin(), p.end());
    unordered_map<int, ull> dp;
    vector<int> s;
    s.push_back(0);
    ull ans = 0;
    for(auto &i : p)
    {
        dp[i.end_day] = max({dp[i.end_day], 
            dp[*(upper_bound(s.begin(), s.end(), i.start_day-1)-1)]+i.money, 
            dp[*(upper_bound(s.begin(), s.end(), i.end_day-1)-1)]});
        s.push_back(i.end_day);
        ans = max(ans, dp[i.end_day]);
    }
    cout << ans;
}
