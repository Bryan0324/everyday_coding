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
    set<int> s;
    queue<int> lq;
    int ans = 0;
    for(auto &i : k)
    {
        if(s.count(i) == 0)
        {
            lq.push(i);
            s.insert(i);
        }else
        {
            while(!lq.empty())
            {
                if(lq.front() == i)break;
                s.erase(lq.front());
                lq.pop();
            }
            lq.pop();
            lq.push(i);
        }
        ans = max(ans, (int)lq.size());
    }
    cout << ans;
}