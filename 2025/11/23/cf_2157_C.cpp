#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;


typedef pair<int, pair<int, int>> Quest;
#define pri first
#define l second.first
#define r second.second
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<Quest> qts;
    vector<int> v(n, 0);
    vector<bool> lock(n, false);
    vector<bool> mex(n, false), mi(n, false);
    while(q--)
    {
        Quest i;
        cin >> i.pri >> i.l >> i.r;
        i.l--;
        if(i.pri == 2)
        {
            for(int d = i.l; d < i.r; d++)mex[d] = true;
            qts.push_back(i);
        }else for(int d = i.l; d < i.r; d++)
        {
            mi[d] = true;
            lock[d] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(mi[i] && mex[i])v[i] = k+1;
        else if(mi[i])v[i] = k;
    }
    sort(qts.begin(), qts.end());
    for(auto &i : qts)
    {
        vector<bool> have(k, false);
        for(int d = i.l; d < i.r; d++)
        {
            if(v[d] < k && lock[d])have[v[d]] = true;
        }
        for(int d = i.l; d < i.r; d++)
        {
            if(v[d] < k)if(!have[v[d]])
            {
                lock[d] = true;
                have[v[d]] = true;
            }
        }
        int idx = 0;
        while(idx < k)
        {
            if(!have[idx])break;
            idx++;
        }
        for(int d = i.l; d < i.r && idx < k; d++)
        {
            if(!lock[d] && !mi[d])
            {
                v[d] = idx;
                lock[d] = true;
                idx++;
                while(idx < k)
                {
                    if(!have[idx])break;
                    idx++;
                }
            }
        }
    }
    for(auto &i : v)cout << i << ' ';
    cout << '\n';
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}

/* 
2 2 2 2 2 2 2 2 2

*/