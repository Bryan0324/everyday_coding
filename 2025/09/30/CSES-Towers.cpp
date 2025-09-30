#include<bits/stdc++.h>
using namespace std;
 
 
 
 
using ull = unsigned long long;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; 
    cin >> n;
 
    vector<int> k(n);
    for(auto &i : k)cin >> i;
    multiset<int> s;
    int ans = 0;
    for(auto &i : k)
    {
        auto it = s.upper_bound(i);
        if(it == s.end())s.insert(i);
        else
        {
            s.erase(it);
            s.insert(i);
        }
        ans = max(ans, (int)s.size());
    }
    cout << ans;
}
