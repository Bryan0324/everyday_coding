#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ll INF = LONG_LONG_MAX>>1;

typedef pair<ll, int> path;
#define val first
#define to second
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> tmp(n);
    for(auto &i : tmp)cin >> i;
    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == 1)tmp[i] = 2;
        if(a.count(tmp[i]))
        {
            a.erase(tmp[i]);
            if(tmp[i] == 3)tmp.push_back(tmp[i]-1);
            else tmp.push_back(tmp[i] - 2);
            tmp.push_back(tmp[i] + 1);
        }else a.insert(tmp[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int hold = 2;
        auto it = a.begin();
        while(it != a.end())
        {
            if((*it == 2 && hold == 2) || (*it - hold == 1))
            {
                hold = *it + 1;
                a.erase(it++);
                continue;
            }
            if(*it < hold && hold - *it == 1)
            {
                hold += 1;
                a.erase(it++);
                continue;
            }
            break;
        }
        a.insert(hold);
        cout << a.size() << ' ';
    }
}