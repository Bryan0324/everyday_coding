#include<bits/stdc++.h>
using namespace std;
 
 
 
 
using ull = unsigned long long;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    ull ans = 0;
    cin >> n;
    vector<int> x(n);
    for(auto &i : x)cin >> i;
    set<int> s;
    queue<int> diff_q;
    for(auto &i : x)
    {
        diff_q.push(i);
        if(s.count(i) == 0)s.insert(i);
        else
        {
            while(!diff_q.empty())
            {
                if(diff_q.front() == i)break;
                s.erase(diff_q.front());
                diff_q.pop();
            }
            diff_q.pop();
        }
        ans += diff_q.size();
    }
    cout << ans;
}